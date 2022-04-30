#include "rgb_matrix.h"
#include "rgb_matrix_sn32f24xx.h"

#if !defined(RGB_MATRIX_HUE_STEP)
#    define RGB_MATRIX_HUE_STEP 8
#endif

#if !defined(RGB_MATRIX_SAT_STEP)
#    define RGB_MATRIX_SAT_STEP 16
#endif

#if !defined(RGB_MATRIX_VAL_STEP)
#    define RGB_MATRIX_VAL_STEP 16
#endif

#if !defined(RGB_MATRIX_SPD_STEP)
#    define RGB_MATRIX_SPD_STEP 16
#endif

/*
    COLS key / led
    SS8050 transistors NPN driven low
    base      - GPIO
    collector - LED Col pins
    emitter   - VDD

    VDD     GPIO
    (E)     (B)
     |  NPN  |
     |_______|
         |
         |
        (C)
        LED

    ROWS RGB
    SS8550 transistors PNP driven high
    base      - GPIO
    collector - LED RGB row pins
    emitter   - GND

        LED
        (C)
         |
         |
      _______
     |  PNP  |
     |       |
    (B)     (E)
    GPIO    GND
*/

static uint8_t chan_col_order[LED_MATRIX_COLS] = {0}; // track the channel col order
static uint8_t current_row = 0; // LED row scan counter
static uint8_t row_idx = 0; // key row scan counter
extern matrix_row_t raw_matrix[MATRIX_ROWS]; //raw values
static const uint32_t freq = (RGB_MATRIX_HUE_STEP * RGB_MATRIX_SAT_STEP * RGB_MATRIX_VAL_STEP * RGB_MATRIX_SPD_STEP * RGB_MATRIX_LED_PROCESS_LIMIT);
static const pin_t led_row_pins[LED_MATRIX_ROWS_HW] = LED_MATRIX_ROW_PINS; // We expect a R,B,G order here
static const pin_t led_col_pins[LED_MATRIX_COLS] = LED_MATRIX_COL_PINS;
RGB led_state[DRIVER_LED_TOTAL]; // led state buffer
bool enable_pwm = false;

/* PWM configuration structure. We use timer CT16B0, CT16B1, CT16B2, CT32B0, CT32B1, CT32B2, total 21 channels. */
static PWMConfig pwmcfg = {
    freq,          /* PWM clock frequency. */
    256,           /* PWM period (in ticks) 1S (1/10kHz=0.1mS 0.1ms*10000 ticks=1S) */
    NULL,          /* RGB Callback */
    {              /* Default all channels to disabled - Channels will be configured durring init */
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL}
    },
    0/* HW dependent part.*/
};

void rgb_ch_ctrl(PWMConfig *cfg) {
    /* Enable PWM function, IOs and select the PWM modes for the LED column pins */
    for(uint8_t i = 0; i < LED_MATRIX_COLS; i++) {
        switch(led_col_pins[i]) {
            // Intentional fall-through for the PWM B-pin mapping
            case A0:
                cfg->channels[0].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 0;
                break;

            case A1:
                cfg->channels[1].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 1;
                break;

            case A2:
                cfg->channels[2].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 2;
                break;

            case A3:
                cfg->channels[3].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 3;
                break;

            case A4:
                cfg->channels[4].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 4;
                break;

            case A5:
                cfg->channels[5].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 5;
                break;

            case A6:
                cfg->channels[6].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 6;
                break;

            case A7:
                cfg->channels[7].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 7;
                break;

            case A14:
                cfg->channels[8].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 8;
                break;

            case A15:
                cfg->channels[9].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 9;
                break;

            case B0:
                cfg->channels[10].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 10;
                break;

            case B1:
                cfg->channels[11].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 11;
                break;

            case B2:
                cfg->channels[12].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 12;
                break;

            case B3:
                cfg->channels[13].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 13;
                break;

            case B4:
                cfg->channels[14].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 14;
                break;

            case B10:
                cfg->channels[15].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 15;
                break;

            case B11:
                cfg->channels[16].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 16;
                break;

            case B12:
                cfg->channels[17].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 17;
                break;

            case B13:
                cfg->channels[18].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 18;
                break;

            case B14:
                cfg->channels[19].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 19;
                break;

            case B15:
                cfg->channels[20].mode = PWM_OUTPUT_ACTIVE_LOW;
                chan_col_order[i] = 20;
                break;
        }
    }
}

void rgb_callback(PWMDriver *pwmp);

void shared_matrix_rgb_enable(void) {
    pwmcfg.callback = rgb_callback;
    pwmEnablePeriodicNotification(&PWMD1);
}

void shared_matrix_rgb_disable_pwm(void) {
    // Disable PWM outputs on column pins
    for(uint8_t y = 0; y < LED_MATRIX_COLS; y++) {
        pwmDisableChannel(&PWMD1,chan_col_order[y]);
        pwmDisableChannel(&PWMD2,chan_col_order[y]);
        pwmDisableChannel(&PWMD3,chan_col_order[y]);
        pwmDisableChannel(&PWMD4,chan_col_order[y]);
        pwmDisableChannel(&PWMD5,chan_col_order[y]);
        pwmDisableChannel(&PWMD6,chan_col_order[y]);
    }
}

void shared_matrix_rgb_disable_leds(void) {
    // Disable LED outputs on RGB channel pins
    for (uint8_t x = 0; x < LED_MATRIX_ROWS_HW; x++) {
        writePinLow(led_row_pins[x]);
    }
}

void update_pwm_channels(PWMDriver *pwmp) {
    for(uint8_t col_idx = 0; col_idx < LED_MATRIX_COLS; col_idx++) {
        #if(DIODE_DIRECTION == ROW2COL)
            // Scan the key matrix column
            matrix_scan_keys(raw_matrix,col_idx);
        #endif
        uint8_t led_index = g_led_config.matrix_co[row_idx][col_idx];
        // Check if we need to enable RGB output
        if (led_state[led_index].r != 0) enable_pwm |= true;
        if (led_state[led_index].g != 0) enable_pwm |= true;
        if (led_state[led_index].b != 0) enable_pwm |= true;
        // Update matching RGB channel PWM configuration
        switch(current_row % LED_MATRIX_ROW_CHANNELS) {
        case 0:
                if(enable_pwm) pwmEnableChannelI(pwmp,chan_col_order[col_idx],led_state[led_index].r);
            break;
        case 1:
                if(enable_pwm) pwmEnableChannelI(pwmp,chan_col_order[col_idx],led_state[led_index].g);
            break;
        case 2:
                if(enable_pwm) pwmEnableChannelI(pwmp,chan_col_order[col_idx],led_state[led_index].b);
            break;
        default:
            ;
        }
    }
}
void rgb_callback(PWMDriver *pwmp) {
    // Disable the interrupt
    pwmDisablePeriodicNotification(pwmp);
    // Advance to the next LED RGB channel
    current_row++;
    if(current_row >= LED_MATRIX_ROWS_HW) current_row = 0;
    // Advance to the next key matrix row
    if(current_row % LED_MATRIX_ROW_CHANNELS == 2) row_idx++;
    if(row_idx >= LED_MATRIX_ROWS) row_idx = 0;
    chSysLockFromISR();
    // Disable LED output before scanning the key matrix
    shared_matrix_rgb_disable_leds();
    shared_matrix_rgb_disable_pwm();
    #if(DIODE_DIRECTION == COL2ROW)
        // Scan the key matrix row
        matrix_scan_keys(raw_matrix, row_idx);
    #endif
    update_pwm_channels(pwmp);
    if(enable_pwm) writePinHigh(led_row_pins[current_row]);
    chSysUnlockFromISR();
    // Advance the timer to just before the wrap-around, that will start a new PWM cycle
    pwm_lld_change_counter(&PWMD1, 0xFFFF);
    pwm_lld_change_counter(&PWMD2, 0xFFFF);
    pwm_lld_change_counter(&PWMD3, 0xFFFF);
    pwm_lld_change_counter(&PWMD4, 0xFFFFFFFF);
    pwm_lld_change_counter(&PWMD5, 0xFFFFFFFF);
    pwm_lld_change_counter(&PWMD6, 0xFFFFFFFF);
    // Enable the interrupt
    pwmEnablePeriodicNotification(pwmp);
}

void SN32F24XX_init(void) {
    for (uint8_t x = 0; x < LED_MATRIX_ROWS_HW; x++) {
        setPinOutput(led_row_pins[x]);
        writePinLow(led_row_pins[x]);
    }
    // Determine which PWM channels we need to control
    rgb_ch_ctrl(&pwmcfg);
    pwmStart(&PWMD1, &pwmcfg);
    pwmStart(&PWMD2, &pwmcfg);
    pwmStart(&PWMD3, &pwmcfg);
    pwmStart(&PWMD4, &pwmcfg);
    pwmStart(&PWMD5, &pwmcfg);
    pwmStart(&PWMD6, &pwmcfg);
    shared_matrix_rgb_enable();
}

static void flush(void) {} // Due to the way we do PWM, every cycle is a flush

void SN32F24XX_set_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    led_state[index].r = r;
    led_state[index].g = g;
    led_state[index].b = b;
}

void SN32F24XX_set_color_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i=0; i<DRIVER_LED_TOTAL; i++) {
        SN32F24XX_set_color(i, r, g, b);
    }
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init          = SN32F24XX_init,
    .flush         = flush,
    .set_color     = SN32F24XX_set_color,
    .set_color_all = SN32F24XX_set_color_all,
};

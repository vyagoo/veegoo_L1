#ifndef _CAMERAPLAY_LOG_H
#define _CAMERAPLAY_LOG_H

extern int log_dbg_en;

/* for internel debug */
#define log_dbg(x,arg...) do{ \
                                if(log_dbg_en) \
                                    printf("[DEBUG]"x,##arg); \
                            }while(0)

/* print when error happens */
#define log_err(x,arg...) do{ \
                                printf("\033[1m\033[;31m[ERR]"x"\033[0m",##arg); \
                                fflush(stdout); \
                            }while(0)

#define log_warn(x,arg...) printf("[WARN]"x,##arg)
/* print unconditional, for important info */
#define log_printf(x,arg...) printf("[INFO]"x,##arg)

#endif

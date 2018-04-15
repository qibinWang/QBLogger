//
//  QBLogger.h
//  QBLogger
//
//  Created by wangqibin on 2018/4/15.
//  Copyright © 2018年 wangqibin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(unsigned char, QBLogLevel){
        QBLog_None  = 0,
        QBLog_Error = 1 << 0,
        QBLog_Warn  = 1 << 1,
        QBLog_Debug = 1 << 2,
        QBLog_Info  = 1 << 3,
};

#ifdef  DEBUG
#define QBLOGD(...)  [[QBLogger sharedInstance] output:QBLog_Debug fmt:__VA_ARGS__];
#define QBLOGW(...)  [[QBLogger sharedInstance] output:QBLog_Warn  fmt:__VA_ARGS__];
#define QBLOGE(...)  [[QBLogger sharedInstance] output:QBLog_Error fmt:__VA_ARGS__];
#define QBLOGI(...)  [[QBLogger sharedInstance] output:QBLog_Info  fmt:__VA_ARGS__];

//带行号 函数名的实现
#define _QBLOGD(...)  [[QBLogger sharedInstance] output:QBLog_Debug funcName:__func__ line:__LINE__ fmt:__VA_ARGS__];
#define _QBLOGW(...)  [[QBLogger sharedInstance] output:QBLog_Warn  funcName:__func__ line:__LINE__ fmt:__VA_ARGS__];
#define _QBLOGE(...)  [[QBLogger sharedInstance] output:QBLog_Error funcName:__func__ line:__LINE__ fmt:__VA_ARGS__];
#define _QBLOGI(...)  [[QBLogger sharedInstance] output:QBLog_Info  funcName:__func__ line:__LINE__ fmt:__VA_ARGS__];
#else

#define QBLOGD(...)
#define QBLOGW(...)
#define QBLOGE(...)
#define QBLOGI(...)

#define _QBLOGD(...)
#define _QBLOGW(...)
#define _QBLOGE(...)
#define _QBLOGI(...)
//#define NSLog(...) LOGD(...)
#endif

#define QBInstance [QBLogger sharedInstance]

@interface QBLogger : NSObject

+(instancetype)sharedInstance;

-(void)output:(QBLogLevel)level fmt:(NSString *)fmt, ...;

-(void)output:(QBLogLevel)level funcName:(const char *)funcName line:(int)line fmt:(NSString *)fmt, ...;
/**
 *  默认输出全部log
 */
@property(atomic, assign)QBLogLevel  logLevel;

@end

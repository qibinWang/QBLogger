//
//  QBLogger.m
//  QBLogger
//
//  Created by wangqibin on 2018/4/15.
//  Copyright © 2018年 wangqibin. All rights reserved.
//

#import "QBLogger.h"

@implementation QBLogger

+(instancetype)sharedInstance{
    static  QBLogger *obj = nil;
    static dispatch_once_t predicate;
    dispatch_once(&predicate, ^{
        obj = [[self alloc] init];
        obj.logLevel = 0;
    });
    return obj;
}

-(void)output:(QBLogLevel)level fmt:(NSString *)fmt, ...{
    if (!fmt || ![fmt isKindOfClass:[NSString class]])
        return;
    else{
        if (!(_logLevel&level))
            return;
        else{
            va_list args;
            va_start(args, fmt);
            NSString *log = [[NSString alloc] initWithFormat:fmt arguments:args];
            fprintf(stdout, "[%s] %s\n", [[self level2String:level] UTF8String], [log UTF8String]);
              va_end(args);
        }
    }
}

-(void)output:(QBLogLevel)level funcName:(const char *)funcName line:(int)line fmt:(NSString *)fmt, ...{
    if (!fmt || ![fmt isKindOfClass:[NSString class]])
        return;
    else{
        if (!(_logLevel&level))
            return;
        else{
          va_list args;
            va_start(args, fmt);
            NSString *log = [[NSString alloc] initWithFormat:fmt arguments:args];
            fprintf(stdout, "[%s %s %d] %s\n", [[self level2String:level] UTF8String], funcName, line, [log UTF8String]);
            va_end(args);
        }
    }
}

-(NSString *)level2String:(QBLogLevel)level{
    if (level == QBLog_None)  return @"QBLog_None";
    if (level == QBLog_Error) return @"QBLog_Error";
    if (level == QBLog_Warn)  return @"QBLog_Warn";
    if (level == QBLog_Debug) return @"QBLog_Debug";
    if (level == QBLog_Info)  return @"QBLog_Info";
    return @"Undefined";
}

@end

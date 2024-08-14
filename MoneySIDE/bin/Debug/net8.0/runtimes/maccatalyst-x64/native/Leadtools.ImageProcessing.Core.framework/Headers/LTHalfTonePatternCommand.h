// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTHalfTonePatternCommand.h
//  Leadtools.ImageProcessing.Core-macOS_22
//


#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>
#import <Leadtools/LTRasterColor.h>

typedef NS_ENUM(NSUInteger, LTHalfTonePatternCommandType) {
    LTHalfTonePatternCommandTypeNone    = 0x0000,
    LTHalfTonePatternCommandTypeDot     = 0x0001, //HTPATTERN_DOT
    LTHalfTonePatternCommandTypeLine    = 0x0002,//HTPATTERN_LINE
    LTHalfTonePatternCommandTypeCircle  = 0x0003,//HTPATTERN_CIRCLE
    LTHalfTonePatternCommandTypeEllipse = 0x0004,//HTPATTERN_ELLIPSE
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTHalfTonePatternCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger contrast;
@property (nonatomic, assign) NSInteger ripple;
@property (nonatomic, assign) NSInteger angleContrast;
@property (nonatomic, assign) NSInteger angleRipple;
@property (nonatomic, assign) NSInteger angleOffset;
@property (nonatomic, retain) LTRasterColor* backgroundColor;
@property (nonatomic, retain) LTRasterColor* foregroundColor;
@property (nonatomic, assign) LTHalfTonePatternCommandType type;

- (instancetype)initWithValues:(NSInteger)contrast ripple:(NSInteger)ripple angleContrast:(NSInteger)angleContrast angleRipple:(NSInteger)angleRipple angleOffset:(NSInteger)angleOffset backgroundColor:(LTRasterColor*)backgroundColor foregroundColor:(LTRasterColor*)foregroundColor type:(LTHalfTonePatternCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

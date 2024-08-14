// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTHighQualityRotateCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

typedef NS_OPTIONS(NSUInteger, LTHighQualityRotateCommandFlags) {
    LTHighQualityRotateCommandFlagsNone        = 0x0000,
    LTHighQualityRotateCommandFlagsCrop        = 0x0000,
    LTHighQualityRotateCommandFlagsResize      = 0x0001,
    LTHighQualityRotateCommandFlagsFastest     = 0x0000,
    LTHighQualityRotateCommandFlagsBestQuality = 0x0010
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTHighQualityRotateCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger angle;
@property (nonatomic, assign) LTHighQualityRotateCommandFlags flags;
@property (nonatomic, copy)   LTRasterColor *fillColor;

- (instancetype)initWithAngle:(NSInteger)angle flags:(LTHighQualityRotateCommandFlags)flags fillColor:(LTRasterColor*)fillColor NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

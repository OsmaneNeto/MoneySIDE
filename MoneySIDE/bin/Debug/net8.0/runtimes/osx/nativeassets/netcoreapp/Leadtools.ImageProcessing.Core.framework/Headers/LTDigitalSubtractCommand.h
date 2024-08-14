// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDigitalSubtractCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>

typedef NS_OPTIONS(NSUInteger, LTDigitalSubtractCommandFlags) {
    LTDigitalSubtractCommandFlagsNone                 = 0x0000,
    LTDigitalSubtractCommandFlagsContrastEnhancement  = 0x0001,
    LTDigitalSubtractCommandFlagsOptimizeRange        = 0x0002,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDigitalSubtractCommand : LTRasterCommand

@property (nonatomic, strong, nullable) LTRasterImage *maskImage;
@property (nonatomic, assign)           LTDigitalSubtractCommandFlags flags;

- (instancetype)initWithMaskImage:(LTRasterImage *)maskImage flags:(LTDigitalSubtractCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTFourierTransformDisplayCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools.ImageProcessing.Core/LTFourierTransformInformation.h>

typedef NS_OPTIONS(NSUInteger, LTFourierTransformDisplayCommandFlags) {
    LTFourierTransformDisplayCommandFlagsNone      = 0x0000,
    LTFourierTransformDisplayCommandFlagsMagnitude = 0x0001,
    LTFourierTransformDisplayCommandFlagsPhase     = 0x0002,
    LTFourierTransformDisplayCommandFlagsNormal    = 0x0010,
    LTFourierTransformDisplayCommandFlagsLog       = 0x0020
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTFourierTransformDisplayCommand : LTRasterCommand

@property (nonatomic, assign)                   LTFourierTransformDisplayCommandFlags flags;
@property (nonatomic, strong, null_unspecified) LTFourierTransformInformation *fourierTransformInformation;

- (instancetype)initWithInformation:(null_unspecified LTFourierTransformInformation *)information flags:(LTFourierTransformDisplayCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

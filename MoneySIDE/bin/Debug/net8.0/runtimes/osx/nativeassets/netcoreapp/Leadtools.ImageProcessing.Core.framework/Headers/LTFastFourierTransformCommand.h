// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTFastFourierTransformCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools.ImageProcessing.Core/LTFourierTransformInformation.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTFastFourierTransformCommand : LTRasterCommand

@property (nonatomic, assign) LTFastFourierTransformCommandFlags flags;
@property (nonatomic, strong) LTFourierTransformInformation *fourierTransformInformation;

- (instancetype)initWithInformation:(LTFourierTransformInformation *)information flags:(LTFastFourierTransformCommandFlags)flags NS_DESIGNATED_INITIALIZER;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END

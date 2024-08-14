// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTApplyTransformationParametersCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTApplyTransformationParametersCommandFlags) {
    LTApplyTransformationParametersCommandFlagsNone       = 0x0000,
    LTApplyTransformationParametersCommandFlagsNormal     = 0x0001,
    LTApplyTransformationParametersCommandFlagsResample   = 0x0002,
    LTApplyTransformationParametersCommandFlagsBicubic    = 0x0003,
    LTApplyTransformationParametersCommandFlagsFavorBlack = 0x0010,
    LTApplyTransformationParametersCommandFlagsFavorWhite = 0x0020,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTApplyTransformationParametersCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger xTranslation;
@property (nonatomic, assign) NSInteger yTranslation;
@property (nonatomic, assign) NSInteger angle;
@property (nonatomic, assign) NSUInteger xScale;
@property (nonatomic, assign) NSUInteger yScale;
@property (nonatomic, assign) LTApplyTransformationParametersCommandFlags flags;

- (instancetype)initWithXTranslation:(NSInteger)xTranslation yTranslation:(NSInteger)yTranslation angle:(NSInteger)angle xScale:(NSUInteger)xScale yScale:(NSUInteger)yScale flags:(LTApplyTransformationParametersCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

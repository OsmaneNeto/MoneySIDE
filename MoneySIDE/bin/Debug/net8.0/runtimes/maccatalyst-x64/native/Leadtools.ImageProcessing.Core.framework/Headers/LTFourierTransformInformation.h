// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTFourierTransformInformation.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterImage.h>

typedef struct {
    double r;
    double i;
} LTComplex;

LEADTOOLS_EXPORT LTComplex LTComplexCreate(double r, double i);
LEADTOOLS_EXPORT const LTComplex LTComplexZero NS_SWIFT_NAME(LTComplex.zero);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef NS_OPTIONS(NSUInteger, LTFastFourierTransformCommandFlags) {
    LTFastFourierTransformCommandFlagsNone                        = 0x0000,
    LTFastFourierTransformCommandFlagsFastFourierTransform        = 0x00000001,
    LTFastFourierTransformCommandFlagsInverseFastFourierTransform = 0x00000002,
    LTFastFourierTransformCommandFlagsBlue                        = 0x00000010,
    LTFastFourierTransformCommandFlagsGreen                       = 0x00000020,
    LTFastFourierTransformCommandFlagsRed                         = 0x00000030,
    LTFastFourierTransformCommandFlagsGray                        = 0x00000040,
    LTFastFourierTransformCommandFlagsMagnitude                   = 0x00000100,
    LTFastFourierTransformCommandFlagsPhase                       = 0x00000200,
    LTFastFourierTransformCommandFlagsBoth                        = 0x00000300,
    LTFastFourierTransformCommandFlagsClip                        = 0x00001000,
    LTFastFourierTransformCommandFlagsScale                       = 0x00002000,
    LTFastFourierTransformCommandFlagsPadOptimally                = 0x00010000,
    LTFastFourierTransformCommandFlagsPadSquare                   = 0x00020000,
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTFourierTransformInformation : NSObject

@property (nonatomic, assign, readonly) NSUInteger dataSize;
@property (nonatomic, assign, readonly) NSUInteger width;
@property (nonatomic, assign, readonly) NSUInteger height;

@property (nonatomic, assign, nullable) const LTComplex *data;
- (const LTComplex *)data NS_RETURNS_INNER_POINTER;

- (nullable instancetype)init:(NSError **)error NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithImage:(LTRasterImage *)image error:(NSError **)error;
- (nullable instancetype)initWithImage:(LTRasterImage *)image flags:(LTFastFourierTransformCommandFlags)flags error:(NSError **)error NS_DESIGNATED_INITIALIZER;
- (instancetype)init __unavailable;

- (LTComplex)dataAtRow:(NSUInteger)x column:(NSUInteger)y;

@end

NS_ASSUME_NONNULL_END

// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDiscreteFourierTransformCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

#import <Leadtools.ImageProcessing.Core/LTFourierTransformInformation.h>

typedef NS_OPTIONS(NSUInteger, LTDiscreteFourierTransformCommandFlags) {
    LTDiscreteFourierTransformCommandFlagsNone                            = 0x0000,
    LTDiscreteFourierTransformCommandFlagsDiscreteFourierTransform        = 0x00000001,
    LTDiscreteFourierTransformCommandFlagsInverseDiscreteFourierTransform = 0x00000002,
    LTDiscreteFourierTransformCommandFlagsBlue                            = 0x00000010,
    LTDiscreteFourierTransformCommandFlagsGreen                           = 0x00000020,
    LTDiscreteFourierTransformCommandFlagsRed                             = 0x00000030,
    LTDiscreteFourierTransformCommandFlagsGray                            = 0x00000040,
    LTDiscreteFourierTransformCommandFlagsMagnitude                       = 0x00000100,
    LTDiscreteFourierTransformCommandFlagsPhase                           = 0x00000200,
    LTDiscreteFourierTransformCommandFlagsBoth                            = 0x00000300,
    LTDiscreteFourierTransformCommandFlagsClip                            = 0x00001000,
    LTDiscreteFourierTransformCommandFlagsScale                           = 0x00002000,
    LTDiscreteFourierTransformCommandFlagsAll                             = 0x00010000,
    LTDiscreteFourierTransformCommandFlagsRange                           = 0x00020000,
    LTDiscreteFourierTransformCommandFlagsInsideX                         = 0x00100000,
    LTDiscreteFourierTransformCommandFlagsOutsideX                        = 0x00200000,
    LTDiscreteFourierTransformCommandFlagsInsideY                         = 0x01000000,
    LTDiscreteFourierTransformCommandFlagsOutsideY                        = 0x02000000
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDiscreteFourierTransformCommand : LTRasterCommand

@property (nonatomic, assign) LTDiscreteFourierTransformCommandFlags flags;

@property (nonatomic, assign) LeadRect range;

@property (nonatomic, strong) LTFourierTransformInformation *fourierTransformInformation;

- (instancetype)initWithInformation:(LTFourierTransformInformation *)information range:(LeadRect)range flags:(LTDiscreteFourierTransformCommandFlags)flags NS_DESIGNATED_INITIALIZER;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END

// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCLAHECommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTCLAHECommandFlags) {
    LTCLAHECommandFlagsApplyNormalDistribution      = 0x00004,
    LTCLAHECommandFlagsApplyExponentialDistribution = 0x00002,
    LTCLAHECommandFlagsApplyRayliehDistribution     = 0x00001,
    LTCLAHECommandFlagsApplySigmoidDistribution     = 0x00008,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCLAHECommand : LTRasterCommand

@property (nonatomic, assign) NSInteger tilesNumber;
@property (nonatomic, assign) NSInteger binNumber;
@property (nonatomic, assign) float alphaFactor;
@property (nonatomic, assign) float tileHistClipLimit;
@property (nonatomic, assign) LTCLAHECommandFlags flags;

- (instancetype)initWithAlpha:(float)alpha tilesNumber:(NSInteger)tilesNumber tileHistClipLimit:(float)tileHistClipLimit binNumber:(NSInteger)binNumber flags:(LTCLAHECommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

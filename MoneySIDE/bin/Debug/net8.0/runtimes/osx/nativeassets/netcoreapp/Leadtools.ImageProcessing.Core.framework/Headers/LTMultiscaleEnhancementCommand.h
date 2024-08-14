// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTMultiscaleEnhancementCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTMultiscaleEnhancementCommandType) {
    LTMultiscaleEnhancementCommandTypeGaussian = 0x0000,
    LTMultiscaleEnhancementCommandTypeResample = 0x0001,
    LTMultiscaleEnhancementCommandTypeBicubic  = 0x0002,
    LTMultiscaleEnhancementCommandTypeNormal   = 0x0003,
};

typedef NS_OPTIONS(NSUInteger, LTMultiscaleEnhancementCommandFlags) {
    LTMultiscaleEnhancementCommandFlagsNone              = 0x0000,
    LTMultiscaleEnhancementCommandFlagsEdgeEnhancement   = 0x0010,
    LTMultiscaleEnhancementCommandFlagsLatitudeReduction = 0x0020,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTMultiscaleEnhancementCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger contrast;
@property (nonatomic, assign) NSUInteger edgeLevels;
@property (nonatomic, assign) NSUInteger edgeCoefficient;
@property (nonatomic, assign) NSUInteger latitudeLevels;
@property (nonatomic, assign) NSUInteger latitudeCoefficient;
@property (nonatomic, assign) LTMultiscaleEnhancementCommandType type;
@property (nonatomic, assign) LTMultiscaleEnhancementCommandFlags flags;

- (instancetype)initWithContrast:(NSUInteger)contrast;
- (instancetype)initWithContrast:(NSUInteger)contrast type:(LTMultiscaleEnhancementCommandType)type flags:(LTMultiscaleEnhancementCommandFlags)flags;
- (instancetype)initWithContrast:(NSUInteger)contrast edgeLevels:(NSUInteger)edgeLevels edgeCoefficient:(NSUInteger)edgeCoefficient latitudeLevels:(NSUInteger)latitudeLevels latitudeCoefficient:(NSUInteger)latitudeCoefficient type:(LTMultiscaleEnhancementCommandType)type flags:(LTMultiscaleEnhancementCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTGrayscaleToMultitoneCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

#import <Leadtools.ImageProcessing.Color/LTEnums.h>

typedef NS_ENUM(NSInteger, LTGrayScaleToMultitoneCommandToneType) {
    LTGrayScaleToMultitoneCommandToneTypeMonotone = 0x00000000,
    LTGrayScaleToMultitoneCommandToneTypeDuotone  = 0x00000001,
    LTGrayScaleToMultitoneCommandToneTypeTritone  = 0x00000002,
    LTGrayScaleToMultitoneCommandToneTypeQuadtone = 0x00000003
};

typedef NS_ENUM(NSInteger, LTGrayScaleToMultitoneCommandDistributionType) {
    LTGrayScaleToMultitoneCommandDistributionTypeLinear      = 0x00000000,
    LTGrayScaleToMultitoneCommandDistributionTypeUserDefined = 0x00000001
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTGrayscaleToMultitoneCommand : LTRasterCommand

@property (nonatomic, assign)         LTGrayScaleToDuotoneCommandMixingType type;
@property (nonatomic, assign)         LTGrayScaleToMultitoneCommandToneType tone;
@property (nonatomic, assign)         LTGrayScaleToMultitoneCommandDistributionType distribution;

@property (nonatomic, copy, nullable) NSArray<LTRasterColor *> *colors; // 1 color for monotone, 2 colors for duotone and so forth
@property (nonatomic, copy, nullable) NSArray<NSArray<LTRasterColor *> *> *gradient; // N x 256, where N is 1 for monotone, 2 for duotone and so forth

@end

NS_ASSUME_NONNULL_END

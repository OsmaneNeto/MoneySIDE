// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTColorThresholdCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTColorThresholdCommandType) {
    LTColorThresholdCommandTypeRgb   = 0x00000000,
    LTColorThresholdCommandTypeHsv   = 0x00000001,
    LTColorThresholdCommandTypeHls   = 0x00000002,
    LTColorThresholdCommandTypeXyz   = 0x00000003,
    LTColorThresholdCommandTypeYcrCb = 0x00000004,
    LTColorThresholdCommandTypeYuv   = 0x00000005,
    LTColorThresholdCommandTypeLab   = 0x00000006,
    LTColorThresholdCommandTypeCmy   = 0x00000007
};

typedef NS_OPTIONS(NSUInteger, LTColorThresholdCommandFlags) {
    LTColorThresholdCommandFlagsBandPass      = 0x00000000,
    LTColorThresholdCommandFlagsBandReject    = 0x00000001,
    LTColorThresholdCommandFlagsEffectChannel = 0x00000000,
    LTColorThresholdCommandFlagsEffectAll     = 0x00000010,
    LTColorThresholdCommandFlagsSetToMinimum  = 0x00000000,
    LTColorThresholdCommandFlagsSetToMaximum  = 0x00000100,
    LTColorThresholdCommandFlagsSetToClamp    = 0x00000200,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorThresholdCommandComponent : NSObject

@property (nonatomic, assign) NSInteger minimumRange;
@property (nonatomic, assign) NSInteger maximumRange;

@property (nonatomic, assign) LTColorThresholdCommandFlags flags;

- (instancetype)initWithMinimumRange:(NSInteger)minimumRange maximumRange:(NSInteger)maximumRange flags:(LTColorThresholdCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorThresholdCommand : LTRasterCommand

@property (nonatomic, assign) LTColorThresholdCommandType colorSpace;
@property (nonatomic, strong) NSMutableArray<LTColorThresholdCommandComponent *> *components;

- (instancetype)initWithType:(LTColorThresholdCommandType)type components:(NSArray<LTColorThresholdCommandComponent *> *)components NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

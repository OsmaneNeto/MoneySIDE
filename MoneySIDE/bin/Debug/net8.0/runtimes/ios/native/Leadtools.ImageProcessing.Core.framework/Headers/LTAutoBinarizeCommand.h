// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAutoBinarizeCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTAutoBinarizeCommandFlags) {
    LTAutoBinarizeCommandFlagsUseAutoPreProcessing       = 0x00000000,
    LTAutoBinarizeCommandFlagsDontUsePreProcessing       = 0x00000001,
    LTAutoBinarizeCommandFlagsUseBackGroundElimination   = 0x00000002,
    LTAutoBinarizeCommandFlagsUseColorLeveling           = 0x00000004,
    LTAutoBinarizeCommandFlagsUseAutoThreshold           = 0x00000000,
    LTAutoBinarizeCommandFlagsUseUserThreshold           = 0x00000010,
    LTAutoBinarizeCommandFlagsUsePercentileThreshold     = 0x00000020,
    LTAutoBinarizeCommandFlagsUseMedianThreshold         = 0x00000040
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAutoBinarizeCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger factor;
@property (nonatomic, assign) LTAutoBinarizeCommandFlags flags;

- (instancetype)initWithFactor:(NSUInteger)factor flags:(LTAutoBinarizeCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

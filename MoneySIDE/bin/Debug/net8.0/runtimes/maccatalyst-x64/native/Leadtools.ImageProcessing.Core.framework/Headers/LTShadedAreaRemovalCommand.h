// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTShadedAreaRemovalCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

typedef NS_OPTIONS(NSUInteger, LTShadedAreaRemovalCommandFlags) {
    LTShadedAreaRemovalCommandFlagsCleanUpAuto      = 0x0001,
    LTShadedAreaRemovalCommandFlagsCleanUpFill      = 0x0002,
    LTShadedAreaRemovalCommandFlagsCleanUpPreserve  = 0x0004,
    LTShadedAreaRemovalCommandFlagsInvertBlackCells = 0x0008,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTShadedAreaRemovalCommand : LTRasterCommand

@property (nonatomic, strong)   LTRasterColor *fillColor;
@property (nonatomic, assign)   LTShadedAreaRemovalCommandFlags flags;

@end

NS_ASSUME_NONNULL_END

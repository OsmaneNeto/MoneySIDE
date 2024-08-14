// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSegmentCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTSegmentCommandFlags) {
    LTSegmentCommandFlagsNone   = 0,
    LTSegmentCommandFlagsRgb    = 0x00001,
    LTSegmentCommandFlagsY      = 0x00002,
    LTSegmentCommandFlagsU      = 0x00003,
    LTSegmentCommandFlagsV      = 0x00004,
    LTSegmentCommandFlagsUv     = 0x00005,
    LTSegmentCommandFlagsNgtvUv = 0x00010
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSegmentCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger threshold;
@property (nonatomic, assign) LTSegmentCommandFlags flags;

- (instancetype)initWithThreshold:(NSUInteger)threshold flags:(LTSegmentCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

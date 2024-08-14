// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTHistogramCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTHistogramCommandFlags) {
    LTHistogramCommandFlagsMaster      = 0x0000,
    LTHistogramCommandFlagsRed         = 0x0001,
    LTHistogramCommandFlagsGreen       = 0x0002,
    LTHistogramCommandFlagsBlue        = 0x0003,
    LTHistogramCommandFlagsLowHighBits = 0x0000,
    LTHistogramCommandFlagsAllBits     = 0x0010,
    LTHistogramCommandFlagsForce256    = 0x0100
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTHistogramCommand : LTRasterCommand

@property (nonatomic, assign, readonly, nullable) uint64_t *histogram NS_RETURNS_INNER_POINTER;
@property (nonatomic, assign, readonly)           NSUInteger histogramLength;

@property (nonatomic, assign) LTHistogramCommandFlags channel;

- (instancetype)initWithChannel:(LTHistogramCommandFlags)channel NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

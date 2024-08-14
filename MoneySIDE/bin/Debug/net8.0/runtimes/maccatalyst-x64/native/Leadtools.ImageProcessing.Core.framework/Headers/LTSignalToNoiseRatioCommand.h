// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSignalToNoiseRatioCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSignalToNoiseRatioCommand : LTRasterCommand

@property (nonatomic, assign) NSNumber* snr;

@end

NS_ASSUME_NONNULL_END

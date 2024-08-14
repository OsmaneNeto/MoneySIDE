// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTStatisticsInformationCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTStatisticsInformationCommand : LTRasterCommand

@property (nonatomic, assign)           LTRasterColorChannel channel;
@property (nonatomic, assign)           NSInteger start;
@property (nonatomic, assign)           NSInteger end;

@property (nonatomic, assign, readonly) NSInteger minimum;
@property (nonatomic, assign, readonly) NSInteger median;
@property (nonatomic, assign, readonly) NSInteger maximum;

@property (nonatomic, assign, readonly) unsigned long pixelCount;
@property (nonatomic, assign, readonly) unsigned long totalPixelCount;

@property (nonatomic, assign, readonly) double standardDeviation;
@property (nonatomic, assign, readonly) double mean;
@property (nonatomic, assign, readonly) double percent;

- (instancetype)initWithChannel:(LTRasterColorChannel)channel start:(NSInteger)start end:(NSInteger)end NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

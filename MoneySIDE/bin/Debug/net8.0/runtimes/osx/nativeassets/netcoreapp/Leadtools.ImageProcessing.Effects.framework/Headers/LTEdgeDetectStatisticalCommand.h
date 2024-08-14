// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTEdgeDetectStatisticalCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTEdgeDetectStatisticalCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger dimension;
@property (nonatomic, assign) NSInteger threshold;
@property (nonatomic, copy)   LTRasterColor *edgeColor;
@property (nonatomic, copy)   LTRasterColor *backgroundColor;

- (instancetype)initWithDimension:(NSUInteger)dimension threshold:(NSInteger)threshold edgeColor:(LTRasterColor*)edgeColor backgroundColor:(LTRasterColor *)backgroundColor NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

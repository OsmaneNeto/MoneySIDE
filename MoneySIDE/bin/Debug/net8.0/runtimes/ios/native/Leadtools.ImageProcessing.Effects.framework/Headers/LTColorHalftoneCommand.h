// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTColorHalftoneCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorHalftoneCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger maximumRadius;

@property (nonatomic, assign) NSInteger cyanAngle;
@property (nonatomic, assign) NSInteger magentaAngle;
@property (nonatomic, assign) NSInteger yellowAngle;
@property (nonatomic, assign) NSInteger blackAngle;

- (instancetype)initWithMaximumRadius:(NSUInteger)maximumRadius cyanAngle:(NSInteger)cyanAngle magentaAngle:(NSInteger)magentaAngle yellowAngle:(NSInteger)yellowAngle blackAngle:(NSInteger)blackAngle NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

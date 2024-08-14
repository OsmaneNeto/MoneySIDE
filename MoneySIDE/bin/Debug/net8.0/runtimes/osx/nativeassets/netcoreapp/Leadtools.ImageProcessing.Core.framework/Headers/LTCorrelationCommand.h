// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCorrelationCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCorrelationCommand : LTRasterCommand

@property (nonatomic, strong, nullable) LTRasterImage *correlationImage;
@property (nonatomic, strong, nullable) NSArray<NSValue *> *points; //LeadPoint
@property (nonatomic, assign, readonly) NSUInteger numberOfPoints;
@property (nonatomic, assign)           NSUInteger xStep;
@property (nonatomic, assign)           NSUInteger yStep;
@property (nonatomic, assign)           NSUInteger threshold;

- (instancetype)initWithCorrelationImage:(nullable LTRasterImage *)correlationImage points:(nullable NSArray<NSValue *> *)points xStep:(NSUInteger)xStep yStep:(NSUInteger)yStep threshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

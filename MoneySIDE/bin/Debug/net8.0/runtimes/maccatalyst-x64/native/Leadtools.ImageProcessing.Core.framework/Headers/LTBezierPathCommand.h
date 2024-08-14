// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTBezierPathCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBezierPathCommand : LTRasterCommand

@property (nonatomic, strong, nullable) NSArray<NSValue *> *inPoints;     //LeadPoint
@property (nonatomic, strong, nullable) NSArray<NSValue *> *pathPoints;   //LeadPoint

- (instancetype)initWithInPoints:(nullable NSArray<NSValue *> *)inputPoints NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

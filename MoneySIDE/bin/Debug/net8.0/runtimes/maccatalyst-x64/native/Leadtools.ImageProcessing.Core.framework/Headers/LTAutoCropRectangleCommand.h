// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAutoCropRectangleCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAutoCropRectangleCommand : LTRasterCommand

@property (nonatomic, assign)           NSUInteger threshold;
@property (nonatomic, assign, readonly) LeadRect rectangle;

- (instancetype)initWithThreshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;

@end

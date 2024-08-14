// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTMinimumCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTMinimumCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger dimension;

- (instancetype)initWithDimension:(NSUInteger)dimension NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

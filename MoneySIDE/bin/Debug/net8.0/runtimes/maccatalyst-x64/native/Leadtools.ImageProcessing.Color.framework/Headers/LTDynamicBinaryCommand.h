// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDynamicBinaryCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDynamicBinaryCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger dimension;
@property (nonatomic, assign) NSUInteger localContrast;

- (instancetype)initWithDimension:(NSUInteger)dimension localContrast:(NSUInteger)localContrast NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

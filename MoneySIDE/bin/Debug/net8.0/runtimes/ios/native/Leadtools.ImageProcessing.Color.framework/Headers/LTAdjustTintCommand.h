// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAdjustTintCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAdjustTintCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger angleA;
@property (nonatomic, assign) NSInteger angleB;

- (instancetype)initWithAngleA:(NSInteger)angleA angleB:(NSInteger)angleB NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

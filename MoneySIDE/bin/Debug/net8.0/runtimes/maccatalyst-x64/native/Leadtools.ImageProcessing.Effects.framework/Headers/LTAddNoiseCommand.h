// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAddNoiseCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAddNoiseCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger           range;
@property (nonatomic, assign) LTRasterColorChannel channel;

- (instancetype)initWithRange:(NSUInteger)range channel:(LTRasterColorChannel)channel NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

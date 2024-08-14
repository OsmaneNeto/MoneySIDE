// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTUserFilterCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSInteger, LTUserFilterCommandType) {
    LTUserFilterCommandTypeSum     = 0x0000,
    LTUserFilterCommandTypeMaximum = 0x0001,
    LTUserFilterCommandTypeMinimum = 0x0002
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTUserFilterCommand : LTRasterCommand

@property (nonatomic, assign) NSUInteger filterWidth;
@property (nonatomic, assign) NSUInteger filterHeight;
@property (nonatomic, assign) NSUInteger divisor;
@property (nonatomic, assign) NSInteger  offset;

@property (nonatomic, assign) LeadPoint centerPoint;
@property (nonatomic, assign) LTUserFilterCommandType type;

@property (nonatomic, strong) NSArray<NSNumber *> *matrix;

- (instancetype)initWithFilterWidth:(NSUInteger)filterWidth filterHeight:(NSUInteger)filterHeight centerPoint:(LeadPoint)centerPoint divisor:(NSUInteger)divisor offset:(NSInteger)offset type:(LTUserFilterCommandType)type matrix:(NSArray<NSNumber *> *)matrix NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

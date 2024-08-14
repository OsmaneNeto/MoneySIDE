// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTPreDefinedFilterCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSUInteger, LTPreDefinedFilterType) {
    LTPreDefinedFilterTypeGaussian  = 0x00000001, //CREATE_GAUSSIAN_FILTER
    LTPreDefinedFilterTypeMotion    = 0x00000002, //CREATE_MOTION_FILTER
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTPointSpreadFunctionData : NSObject

@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, strong) NSMutableArray<NSNumber *> *values;

//- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTPreDefinedFilterCommand : LTRasterCommand

@property (nonatomic, strong, readonly) LTPointSpreadFunctionData* psf;
@property (nonatomic, assign) double firstParameter;
@property (nonatomic, assign) double secondParameter;
@property (nonatomic, assign) LTPreDefinedFilterType type;

- (instancetype) initWithValues:(double)firstParameter secondParameter:(double)secondParameter type:(LTPreDefinedFilterType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

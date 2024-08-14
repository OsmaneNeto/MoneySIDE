// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTBinaryFilterCommand.h
//  Leadtools.ImageProcessing.Effects
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTBinaryFilterCommandPredefined) {
    LTBinaryFilterCommandPredefinedErosionOmniDirectional,
    LTBinaryFilterCommandPredefinedErosionHorizontal,
    LTBinaryFilterCommandPredefinedErosionVertical,
    LTBinaryFilterCommandPredefinedErosionDiagonal,
    LTBinaryFilterCommandPredefinedDilationOmniDirectional,
    LTBinaryFilterCommandPredefinedDilationHorizontal,
    LTBinaryFilterCommandPredefinedDilationVertical,
    LTBinaryFilterCommandPredefinedDilationDiagonal,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBinaryFilterCommand : LTRasterCommand

@property (nonatomic, assign)           BOOL maximum;
@property (nonatomic, assign, readonly) NSInteger dimension;

@property (nonatomic, copy, nullable)   NSArray<NSNumber *> *matrix;

- (instancetype)initWithPredefinedBinaryFilter:(LTBinaryFilterCommandPredefined)predefined NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithMaximum:(BOOL)maximum matrix:(nullable NSArray<NSNumber *> *)matrix NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

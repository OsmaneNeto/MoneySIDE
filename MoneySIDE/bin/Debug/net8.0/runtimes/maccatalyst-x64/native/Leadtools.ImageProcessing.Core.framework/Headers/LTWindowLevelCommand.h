// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTWindowLevelCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterColor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTWindowLevelCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger lowBit;
@property (nonatomic, assign) NSInteger highBit;
@property (nonatomic, assign) LTRasterByteOrder order;
@property (nonatomic, strong) NSMutableArray<LTRasterColor *> *lookupTable;

- (instancetype)initWithLookupTable:(NSArray<LTRasterColor *> *)lookupTable lowBit:(NSInteger)lowBit highBit:(NSInteger)highBit order:(LTRasterByteOrder)order NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

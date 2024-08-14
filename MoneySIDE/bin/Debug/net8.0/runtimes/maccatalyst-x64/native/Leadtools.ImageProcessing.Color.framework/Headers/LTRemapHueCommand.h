// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRemapHueCommand.h
//  Leadtools.ImageProcessing.Color
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRemapHueCommand : LTRasterCommand

@property (nonatomic, assign, nullable) const unsigned int *mask;
@property (nonatomic, assign, nullable) const unsigned int *hueTable;
@property (nonatomic, assign, nullable) const unsigned int *saturationTable;
@property (nonatomic, assign, nullable) const unsigned int *valueTable;
@property (nonatomic, assign) NSUInteger lookUpTableLength;

- (instancetype)initWithMask:(nullable const unsigned int *)mask hueTable:(nullable const unsigned int *)hueTable saturationTable:(nullable const unsigned int *)saturationTable valueTable:(nullable const unsigned int *)valueTable lookUpTableLength:(NSUInteger)lookUpTableLength NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

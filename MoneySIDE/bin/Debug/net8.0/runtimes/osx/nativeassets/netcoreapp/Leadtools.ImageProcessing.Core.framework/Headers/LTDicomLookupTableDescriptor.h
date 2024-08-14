// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDicomLookupTableDescriptor.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDicomLookupTableDescriptor : NSObject

@property (nonatomic, assign) NSInteger firstStoredPixelValueMapped;
@property (nonatomic, assign) NSUInteger entryBits;

- (instancetype)initWithFirstStoredPixelValueMapped:(NSInteger)firstStoredPixelValueMapped entryBits:(NSUInteger)entryBits NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

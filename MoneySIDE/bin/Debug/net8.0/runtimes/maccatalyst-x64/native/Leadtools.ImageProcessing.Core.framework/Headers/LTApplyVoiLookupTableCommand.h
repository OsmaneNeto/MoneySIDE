// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTApplyVoiLookupTableCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

#import <Leadtools.ImageProcessing.Core/LTEnums.h>
#import <Leadtools.ImageProcessing.Core/LTDicomLookupTableDescriptor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTApplyVoiLookupTableCommand : LTRasterCommand

@property (nonatomic, strong)           LTDicomLookupTableDescriptor *lookupTableDescriptor;
@property (nonatomic, assign, nullable) const uint16_t *lookupTable;
@property (nonatomic, assign)           NSUInteger lookupTableLength;
@property (nonatomic, assign)           LTVoiLookupTableCommandFlags flags;

- (instancetype)initWithLookupTableDescriptor:(LTDicomLookupTableDescriptor *)lookupTableDescriptor lookupTable:(const uint16_t *)lookupTable lookupTableLength:(NSUInteger)lookupTableLength flags:(LTVoiLookupTableCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

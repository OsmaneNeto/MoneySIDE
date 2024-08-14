// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTApplyModalityLookupTableCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

#import <Leadtools.ImageProcessing.Core/LTEnums.h>
#import <Leadtools.ImageProcessing.Core/LTDicomLookupTableDescriptor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTApplyModalityLookupTableCommand : LTRasterCommand

@property (nonatomic, strong)           LTDicomLookupTableDescriptor *lookupTableDescriptor;
@property (nonatomic, assign, nullable) const unsigned short *lookupTable;
@property (nonatomic, assign)           NSUInteger lookupTableLength;
@property (nonatomic, assign)           LTModalityLookupTableCommandFlags flags;

- (instancetype)initWithLookupTableDescriptor:(LTDicomLookupTableDescriptor *)lookupTableDescriptor lookupTable:(const unsigned short *)lookupTable lookupTableLength:(NSUInteger)lookupTableLength flags:(LTModalityLookupTableCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

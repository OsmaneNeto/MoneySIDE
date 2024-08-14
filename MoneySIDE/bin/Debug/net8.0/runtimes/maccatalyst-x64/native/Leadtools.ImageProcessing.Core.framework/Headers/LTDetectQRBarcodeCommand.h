// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDetectQRBarcodeCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDetectQRBarcodeCommand : LTRasterCommand

@property (nonatomic, assign) LeadRect qrBarcodeBounds;
@property (nonatomic, assign) BOOL containsQRBarcode;

@end

NS_ASSUME_NONNULL_END

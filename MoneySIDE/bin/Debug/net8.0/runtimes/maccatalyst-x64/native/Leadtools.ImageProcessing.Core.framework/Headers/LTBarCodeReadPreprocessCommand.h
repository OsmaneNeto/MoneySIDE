// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTBarCodeReadPreprocessCommand.h
//  Leadtools.ImageProcessing.Core-OSX
//

//#import <Leadtools/LTRasterCommand.h>
//#import <Leadtools/LTPrimitives.h>
//
//typedef NS_ENUM(NSInteger, LTBarcodeTypes) {
//    LTBarcodeTypesUnknown           = 0 ,
//    LTBarcodeTypesLinearBarcode     = 1,
//    LTBarcodeTypesQRBarcode         = 2,
//    LTBarcodeTypesDataMatrixBarcode = 3
//};
//
//typedef NS_OPTIONS(NSUInteger, LTBarCodeReadPreprocessOptions) {
//    LTBarCodeReadPreprocessOptionsUseDefault                  = 0,
//    LTBarCodeReadPreprocessOptionsUseAutoDocumentBinarization = 0x0002,
//    LTBarCodeReadPreprocessOptionsUseDeblurBinarization       = 0x0004,
//    LTBarCodeReadPreprocessOptionsUseFastModeBinarization     = 0x0008
//};
//
//NS_ASSUME_NONNULL_BEGIN
//
//typedef BOOL (^LTBarCodeReadPreprocessCallback)(LTRasterImage * __null_unspecified binarizedImage, LeadRect barcodeZone);
//
//NS_CLASS_AVAILABLE(10_10, 8_0)
//@interface LTBarCodeReadPreprocessCommand : LTRasterCommand
//
//@property (nonatomic, assign, readonly) LTBarcodeTypes barcodeType;
//@property (nonatomic, assign, readonly) LeadRect barcodeLocation;
//@property (nonatomic, assign)           LTBarCodeReadPreprocessOptions options;
//
//- (BOOL)run:(LTRasterImage *)image progress:(nullable LTRasterCommandProgress)progressHandler preprocess:(nullable LTBarCodeReadPreprocessCallback)preprocessCallback error:(NSError **)error;
//
//@end
//
//NS_ASSUME_NONNULL_END

// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTAltoXmlDocumentOptions.h
//  Leadtools.Document.Writer
//

#import <Leadtools.Document.Writer/LTDocumentOptions.h>

typedef NS_ENUM(NSInteger, LTAltoXmlMeasurementUnit) {
    LTAltoXmlMeasurementUnitMM10,
    LTAltoXmlMeasurementUnitInch1200,
    LTAltoXmlMeasurementUnitDpi,
    LTAltoXmlMeasurementUnitPixel
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTAltoXmlDocumentOptions : LTDocumentOptions <NSCopying, NSCoding>

@property (nonatomic, assign)         LTAltoXmlMeasurementUnit measurementUnit;

@property (nonatomic, assign)         NSInteger firstPhysicalPageNumber;

@property (nonatomic, assign)         BOOL formatted;
@property (nonatomic, assign)         BOOL sort;
@property (nonatomic, assign)         BOOL plainText;
@property (nonatomic, assign)         BOOL showGlyphInfo;
@property (nonatomic, assign)         BOOL showGlyphVariants;

@property (nonatomic, copy, nullable) NSString *fileName;
@property (nonatomic, copy, nullable) NSString *processingDateTime;
@property (nonatomic, copy, nullable) NSString *processingAgency;
@property (nonatomic, copy, nullable) NSString *processingStepDescription;
@property (nonatomic, copy, nullable) NSString *processingStepSettings;
@property (nonatomic, copy, nullable) NSString *softwareCreator;
@property (nonatomic, copy, nullable) NSString *softwareName;
@property (nonatomic, copy, nullable) NSString *softwareVersion;
@property (nonatomic, copy, nullable) NSString *applicationDescription;

@property (nonatomic, copy)           NSString *indentation; // Default is \t

@end

NS_ASSUME_NONNULL_END

// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrPage.h
//  Leadtools.Ocr
//

#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTLeadStream.h>
#import <Leadtools/LTPrimitives.h>

#import <Leadtools.Ocr/LTOcrAutoPreprocessPageCommand.h>
#import <Leadtools.Ocr/LTOcrImageSharingMode.h>
#import <Leadtools.Ocr/LTOcrWriteXmlOptions.h>
#import <Leadtools.Ocr/LTOcrZoneCollection.h>
#import <Leadtools.Ocr/LTOcrPageCharacters.h>
#import <Leadtools.Ocr/LTOcrZoneCollection.h>
#import <Leadtools.Ocr/LTOcrProgressData.h>

@class LTOcrDocument;

typedef NS_ENUM(NSInteger, LTOcrPageType) {
   LTOcrPageTypeCurrent = 0,
   LTOcrPageTypeProcessing,
   LTOcrPageTypeOriginal
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrPageAutoPreprocessValues : NSObject <NSSecureCoding, NSCopying>

@property (nonatomic, assign) BOOL isInverted;

@property (nonatomic, assign) NSInteger rotationAngle;  // 100th of a degree
@property (nonatomic, assign) NSInteger deskewAngle;    // 100th of a degree

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrPageAreaOptions : NSObject <NSSecureCoding, NSCopying>

@property (nonatomic, assign) LeadRect area;
@property (nonatomic, assign) NSInteger intersectPercentage; // Between 0 and 100
@property (nonatomic, assign) BOOL useTextZone;

- (instancetype)initWithArea:(LeadRect)area intersectPercentage:(NSInteger)intersectPercentage useTextZone:(BOOL)useTextZone;
+ (instancetype)optionsWithArea:(LeadRect)area intersectPercentage:(NSInteger)intersectPercentage useTextZone:(BOOL)useTextZone OBJC_SWIFT_UNAVAILABLE("use object initializers instead");

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrPage : NSObject

@property (nonatomic, assign, readonly)           BOOL isRecognized;

@property (nonatomic, assign, readonly)           NSUInteger width;
@property (nonatomic, assign, readonly)           NSUInteger height;
@property (nonatomic, assign, readonly)           NSUInteger bitsPerPixel;
@property (nonatomic, assign, readonly)           NSUInteger bytesPerLine;
@property (nonatomic, assign, readonly)           NSUInteger dpiX;
@property (nonatomic, assign, readonly)           NSUInteger dpiY;

@property (nonatomic, assign, readonly)           LTRasterImageFormat originalFormat;

@property (nonatomic, weak, readonly, nullable)   LTOcrDocument *document;
@property (nonatomic, strong, readonly)           LTOcrZoneCollection *zones;

@property (nonatomic, strong, readonly, nullable) NSArray<LTRasterColor *> *palette;

@property (nonatomic, assign, readonly)           NSInteger deskewAngle;
@property (nonatomic, assign, readonly)           NSInteger rotateAngle;
@property (nonatomic, assign, readonly)           BOOL isInverted;

@property (nonatomic, copy, nullable)             LTOcrPageAreaOptions *areaOptions;


- (instancetype)init __unavailable;

- (nullable LTRasterImage *)rasterImageForPageType:(LTOcrPageType)pageType error:(NSError **)error;
- (BOOL)setRasterImage:(LTRasterImage *)image error:(NSError **)error;

- (nullable LTRasterImage *)createThumbnailWithWidth:(NSUInteger)thumbnailWidth height:(NSUInteger)thumbnailHeight error:(NSError **)error NS_SWIFT_NAME(createThumbnail(width:height:));

- (NSInteger)deskewAngle:(NSError **)error NS_SWIFT_NOTHROW;
- (NSInteger)rotateAngle:(NSError **)error NS_SWIFT_NOTHROW;
- (BOOL)isInverted:(NSError **)error NS_SWIFT_NOTHROW;

- (LeadRect)zoneBoundsAtIndex:(NSUInteger)index NS_SWIFT_NAME(zoneBounds(at:));
- (NSInteger)hitTestZone:(LeadPoint)point NS_SWIFT_NAME(hitTestZone(_:));

- (BOOL)autoPreprocess:(LTOcrAutoPreprocessPageCommand)command progress:(nullable LTOcrProgressHandler)progressHandler error:(NSError **)error;
- (BOOL)autoZone:(nullable LTOcrProgressHandler)progressHandler error:(NSError **)error NS_SWIFT_NAME(autoZone(progress:));
- (BOOL)recognize:(nullable LTOcrProgressHandler)progressHandler error:(NSError **)error NS_SWIFT_NAME(recognize(progress:));
- (void)unrecognize;
- (nullable NSString *)textForZoneAtIndex:(NSInteger)index error:(NSError **)error NS_SWIFT_NAME(zoneText(at:));
- (nullable LTOcrPage *)copy:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(copy(error:));

- (nullable LTOcrPageCharacters *)recognizedCharacters:(NSError **)error;
- (BOOL)setRecognizedCharacters:(LTOcrPageCharacters *)pageCharacters error:(NSError **)error;

- (BOOL)saveSvgToStream:(LTLeadStream *)fileName error:(NSError **)error;
- (BOOL)saveSvgToFile:(NSString *)fileName error:(NSError **)error;
- (BOOL)saveSvgToData:(NSMutableData *)fileName error:(NSError **)error;

- (nullable NSArray<NSNumber *> *)detectLanguages:(NSArray<NSNumber *> *)languages error:(NSError **)error;
- (nullable LTOcrPageAutoPreprocessValues *)preprocessValues:(NSError **)error;
- (nullable LTRasterImage *)overlayImage;
- (void)setOverlayImage:(LTRasterImage *)image error:(NSError **)error;

- (BOOL)loadZonesFromStream:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(loadZones(from:pageNumber:));
- (BOOL)saveZonesToStream:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions error:(NSError **)error NS_SWIFT_NAME(saveZones(to:pageNumber:writeOptions:));
- (BOOL)saveXmlToStream:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions outputOptions:(LTOcrXmlOutputOptions)outputOptions error:(NSError **)error NS_SWIFT_NAME(saveXml(to:pageNumber:writeOptions:outputOptions:));

- (BOOL)loadZonesFromFile:(NSString *)fileName pageNumber:(NSUInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(loadZones(from:pageNumber:));
- (BOOL)saveZonesToFile:(NSString *)fileName pageNumber:(NSUInteger)pageNumber xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions error:(NSError **)error NS_SWIFT_NAME(saveZones(to:pageNumber:writeOptions:));
- (BOOL)saveXmlToFile:(NSString *)fileName pageNumber:(NSUInteger)pageNumber xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions outputOptions:(LTOcrXmlOutputOptions)outputOptions error:(NSError **)error NS_SWIFT_NAME(saveXml(to:pageNumber:writeOptions:outputOptions:));

- (BOOL)loadZonesFromData:(NSData *)data pageNumber:(NSUInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(loadZones(from:pageNumber:));
- (BOOL)saveZonesToData:(NSMutableData *)data pageNumber:(NSUInteger)pageNumber xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions error:(NSError **)error NS_SWIFT_NAME(saveZones(to:pageNumber:writeOptions:));
- (BOOL)saveXmlToData:(NSMutableData *)data pageNumber:(NSUInteger)pageNumber xmlWriteOptions:(nullable LTOcrWriteXmlOptions *)xmlWriteOptions outputOptions:(LTOcrXmlOutputOptions)outputOptions error:(NSError **)error NS_SWIFT_NAME(saveXml(to:pageNumber:writeOptions:outputOptions:));

@end



@interface LTOcrPage (Deprecated)

- (nullable LTRasterImage *)getRasterImage:(LTOcrPageType)pageType error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "rasterImageForPageType:error:");
- (nullable LTRasterImage *)createThumbnail:(unsigned int)thumbnailWidth thumbnailHeight:(unsigned int)thumbnailHeight error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "createThumbnailWithWidth:height:error:");
- (nullable NSData *)getPalette LT_DEPRECATED_USENEW(19_0, "palette");

- (BOOL)autoPreprocess:(LTOcrAutoPreprocessPageCommand)command target:(id)target selector:(SEL)selector error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "autoPreprocess:progress:error:");

- (BOOL)getDeskewAngle:(int*)value error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "deskewAngle:");
- (BOOL)getRotateAngle:(int*)value error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "rotateAngle:");
- (BOOL)isInverted:(BOOL *)value error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "isInverted:");

- (LeadRect)getZoneBoundsInPixels:(unsigned int)zoneIndex LT_DEPRECATED_USENEW(19_0, "zoneBoundsAtIndex:");

- (BOOL)autoZone:(id)target selector:(SEL)selector error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "autoZone:error:");
- (BOOL)recognize:(id)target selector:(SEL)selector error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "recognize:error:");
- (nullable NSString *)getText:(int)zoneIndex error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "textForZoneAtIndex:error:");

- (nullable LTOcrPageCharacters *)getRecognizedCharacters:(NSError **)error LT_DEPRECATED_USENEW(19_0, "recognizedCharacters:");

- (void)loadZones:(LTLeadStream *)stream pageNumber:(unsigned int)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "loadZonesFromStream:pageNumber:error:");
- (void)saveZones:(LTLeadStream *)stream pageNumber:(unsigned int)pageNumber xmlWriteOptions:(LTOcrWriteXmlOptions *)xmlWriteOptions error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "saveZonesToStream:pageNumber:xmlWriteOptions:error");
- (void)saveXml:(LTLeadStream *)stream pageNumber:(unsigned int)pageNumber xmlWriteOptions:(LTOcrWriteXmlOptions *)xmlWriteOptions outputOptions:(LTOcrXmlOutputOptions)outputOptions error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "saveXmlToStream:pageNumber:xmlWriteOptions:outputOptions:error:");

@end

NS_ASSUME_NONNULL_END

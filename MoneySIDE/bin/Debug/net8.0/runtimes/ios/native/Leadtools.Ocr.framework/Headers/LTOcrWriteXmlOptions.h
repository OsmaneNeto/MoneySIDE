// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTOcrWriteXmlOptions.h
//  Leadtools.Ocr
//

typedef NS_ENUM(NSInteger, LTOcrXmlEncoding) {
   LTOcrXmlEncodingUTF8 = 0,
   LTOcrXmlEncodingUTF16,
};

typedef NS_OPTIONS(NSUInteger, LTOcrXmlOutputOptions) {
   LTOcrXmlOutputOptionsNone                = 0x00,
   LTOcrXmlOutputOptionsCharacters          = 0x01,
   LTOcrXmlOutputOptionsCharacterAttributes = 0x02
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTOcrWriteXmlOptions : NSObject

@property (nonatomic, assign) LTOcrXmlEncoding encoding;

@property (nonatomic, assign) BOOL formatted;

@property (nonatomic, copy)   NSString *indent;



- (instancetype)initWithEncoding:(LTOcrXmlEncoding)encoding formatted:(BOOL)formatted indent:(NSString *)indent NS_DESIGNATED_INITIALIZER;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END

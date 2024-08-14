// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTIDCardZoningCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, LTIDLetterType) {
    LTIDLetterTypeNormal       = 0,
    LTIDLetterTypeMerged       = 1,
    LTIDLetterTypeDisconnected = 2
};

typedef NS_ENUM(NSInteger, LTIDZoneType) {
    LTIDZoneTypeTextZone = 0x0,
};

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTIDCharInfo : NSObject

@property (nonatomic, assign) LTIDLetterType type;
@property (nonatomic, assign) LeadRect bounds;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTIDZoneInfo : NSObject

@property (nonatomic, assign)                     LTIDZoneType type;

@property (nonatomic, assign)                     LeadRect bounds;

@property (nonatomic, assign)                     NSInteger blobsCount;
@property (nonatomic, assign)                     NSInteger charactersCount;
@property (nonatomic, assign)                     NSInteger mergedLettersCount;
@property (nonatomic, assign)                     NSInteger estimatedCharactersCount;
@property (nonatomic, assign)                     NSInteger disconnectedLettersCount;

@property (nonatomic, strong, readonly, nullable) NSArray<LTIDCharInfo *> *charsZones;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTIDCardZoningCommand : LTRasterCommand

@property (nonatomic, assign)                     LeadRect countryZone;

@property (nonatomic, assign)                     BOOL detectCountryZone;
@property (nonatomic, assign)                     BOOL detectEUCountry;
@property (nonatomic, assign)                     BOOL cleanupNoises;

@property (nonatomic, assign)                     NSInteger minTextHeight;
@property (nonatomic, assign)                     NSInteger maxTextHeight;

@property (nonatomic, strong, readonly, nullable) NSArray<LTIDZoneInfo *> *fieldsZones;

@end

NS_ASSUME_NONNULL_END

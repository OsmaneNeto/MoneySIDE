// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTEnums.h
//  Leadtools.ImageProcessing.Core
//

typedef NS_OPTIONS(NSUInteger, LTModalityLookupTableCommandFlags) {
    LTModalityLookupTableCommandFlagsNone                = 0x0000,
    LTModalityLookupTableCommandFlagsSignedLookupTable   = 0x0001,
    LTModalityLookupTableCommandFlagsUpdateMinMax        = 0x0002,
    LTModalityLookupTableCommandFlagsUseFullRange        = 0x0004,
    LTModalityLookupTableCommandFlagsAllowRangeExpansion = 0x0008
};

typedef NS_OPTIONS(NSUInteger, LTVoiLookupTableCommandFlags) {
    LTVoiLookupTableCommandFlagsNone          = 0x0000,
    LTVoiLookupTableCommandFlagsUpdateMinMax  = 0x0001,
    LTVoiLookupTableCommandFlagsReverseOrder  = 0x0002
};

typedef NS_ENUM(NSInteger, LTRemoveStatus) {
    LTRemoveStatusRemove   = 0x0001,
    LTRemoveStatusNoRemove = 0x0002,
    LTRemoveStatusCancel   = -100,
};

typedef NS_ENUM(NSInteger, LTRegistrationMarkCommandType) {
    LTRegistrationMarkCommandTypeTShape   = 0x0000
};

typedef NS_ENUM(NSInteger, LTTransparencyMaskFlags) {
    LTTransparencyMaskFlagsNone
};

typedef NS_ENUM(NSInteger, LTImageColorTypeCommandFlags) {
    LTImageColorTypeCommandFlagsNone,
    LTImageColorTypeCommandFlagsFavorColor = 0x00000001,
    LTImageColorTypeCommandFlagsFavorGrayScale = 2,
    LTImageColorTypeCommandFlagsFavorBlackAndWhite = 1,
};

typedef NS_ENUM(NSInteger, LTImageColorType) {
    LTImageColorTypeNone,
    LTImageColorTypeBlackAndWhite = 1,
    LTImageColorTypeGrayScale = 2,
    LTImageColorTypeColor = 3,
};

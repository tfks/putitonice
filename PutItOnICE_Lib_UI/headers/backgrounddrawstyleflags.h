#ifndef BACKGROUNDDRAWSTYLE_H
#define BACKGROUNDDRAWSTYLE_H

class BackgroundDrawStyleFlags
{
public:
    enum BackgroundDrawStyle
    {
        TopLeft = 1,
        TopRight = 2,
        BottomLeft = 4,
        BottomRight = 8,
        Stretched = 16,
        StretchedWithAspectRatio = 32
    };

    Q_DECLARE_FLAGS(BackgroundDrawStyles, BackgroundDrawStyle);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(BackgroundDrawStyleFlags::BackgroundDrawStyles);

#endif // BACKGROUNDDRAWSTYLE_H

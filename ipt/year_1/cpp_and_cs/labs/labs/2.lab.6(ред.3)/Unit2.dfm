object Form2: TForm2
  Left = 12
  Top = 188
  AutoScroll = False
  AutoSize = True
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'ImageViewer'
  ClientHeight = 650
  ClientWidth = 1297
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF009999
    9999999999999999999999999999966666666666666666666666666666699666
    68868886666666666662F6666669966336666666666666666666666668699666
    666666666666E006666666266F6996666666E0600EF0000E6666666666699666
    666600EFE000000E66666666666996666600F0F000000006F666666666699666
    6000000000000006666666666669966600000000000000046666666666699668
    0000000008800004666666666669966000000000000000006666666666699EE0
    00000000000000004EEEEEEEEEE99EE00088F8F0FF00000008EEEEEEEEE99EE8
    000000000000000000EEEEEEEEE99EEEE0FFFFF8EEEEF844008EEEEFFFE99EFE
    E0888838EEEEEEEE800EEEEEFEE99EEEE0011188EEEEEEEEEEEEEEEEEEE99EFE
    EEE999EEEEEEEEEEEEEEEEEEEEE99EEEEEE0FFEEEEEEEEEEFFFFFFFFEFE99EEE
    EEE088EEFFFFFEFFFFFFFFFFFFF99EEEEEEE8EEEEFFFFEEEFFFEFFFFEFF99EEE
    EEEF8EEEEEEEFEFEFFFFFFFEFFF99FFFFFF8FEEEEEEFEEEFEFFFFFEFEFE99FE8
    E88FEEEEEEEEEEEEFFFFFFEEFEE99FFEFEFFEEEEEEEEEEEFFFFFFFEEEEE99FFF
    FFEEEEEEEEEEEFFFFFFFEEEEEEE99EFEEEEEEEEEEEEEFFEEFFFEEEEEEEE99EEE
    EEEEEEEEEEEEEFFFFFFEEEEEEEE99EEFEFFEEEEEEEEEEEEEFFFEEEEEEEE99EFF
    FEEEEEEEEEEEEEEEEFEEEEEEEEE9999999999999999999999999999999990000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 0
    Width = 1297
    Height = 569
    AutoSize = True
    BorderStyle = bsNone
    Color = clBtnFace
    ParentColor = False
    TabOrder = 0
    TabStop = True
    OnMouseWheelDown = ScrollBox1MouseWheelDown
    OnMouseWheelUp = ScrollBox1MouseWheelUp
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 1297
      Height = 569
      AutoSize = True
      OnMouseDown = Image1MouseDown
    end
  end
  object Panel1: TPanel
    Left = 1
    Top = 569
    Width = 1296
    Height = 81
    TabOrder = 1
    object Button1: TButton
      Left = 1232
      Top = 24
      Width = 33
      Height = 33
      Caption = 'Info'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 536
      Top = 16
      Width = 57
      Height = 49
      Caption = 't'
      Font.Charset = SYMBOL_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Wingdings 3'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 632
      Top = 16
      Width = 57
      Height = 49
      Caption = 'u'
      Font.Charset = SYMBOL_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Wingdings 3'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button3Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 592
    object File1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Caption = 'Open'
        ShortCut = 16463
        OnClick = Open1Click
      end
      object Save1: TMenuItem
        Caption = 'Save as...     '
        ShortCut = 16467
        OnClick = Save1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object System1: TMenuItem
      Caption = 'System'
      ShortCut = 112
      object Shutdown1: TMenuItem
        Caption = 'Shut down      '
        ShortCut = 112
        OnClick = Shutdown1Click
      end
      object Sl1: TMenuItem
        Caption = 'Reboot'
        ShortCut = 113
        OnClick = Sl1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Info1: TMenuItem
        Caption = 'Info'
        Enabled = False
      end
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 56
    Top = 592
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 96
    Top = 592
  end
  object PopupMenu1: TPopupMenu
    AutoPopup = False
    Left = 136
    Top = 592
    object Size1: TMenuItem
      Caption = 'Size'
      object Plus1: TMenuItem
        Caption = 'Plus'
        OnClick = Plus1Click
      end
      object Minus1: TMenuItem
        Caption = 'Minus'
        OnClick = Minus1Click
      end
    end
    object Fullscreen1: TMenuItem
      Caption = 'Full screen'
      Enabled = False
    end
  end
end

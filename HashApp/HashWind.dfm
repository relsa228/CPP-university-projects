object HashForm: THashForm
  Left = 0
  Top = 0
  Caption = #1058#1072#1073#1083#1080#1095#1082#1072
  ClientHeight = 356
  ClientWidth = 434
  Color = clGradientInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object HashLabel: TLabel
    Left = 224
    Top = 21
    Width = 94
    Height = 16
    Caption = #1061#1101#1096'-'#1090#1072#1073#1083#1080#1094#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object AddLabel: TLabel
    Left = 24
    Top = 21
    Width = 63
    Height = 16
    Caption = #1069#1083#1077#1084#1077#1085#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object MinLabel: TLabel
    Left = 24
    Top = 250
    Width = 139
    Height = 16
    Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1099#1081' '#1082#1083#1102#1095':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object FindLabel: TLabel
    Left = 24
    Top = 125
    Width = 43
    Height = 16
    Caption = #1053#1072#1081#1090#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object HashTableMemo: TMemo
    Left = 224
    Top = 40
    Width = 185
    Height = 193
    Lines.Strings = (
      '0. '
      '1. '
      '2. '
      '3. '
      '4. '
      '5. '
      '6. '
      '7. '
      '8. '
      '9. '
      '10. '
      '11. ')
    ReadOnly = True
    ScrollBars = ssHorizontal
    TabOrder = 0
  end
  object DataEdit: TEdit
    Left = 24
    Top = 43
    Width = 161
    Height = 21
    NumbersOnly = True
    TabOrder = 1
    OnChange = DataEditChange
  end
  object AddButton: TButton
    Left = 24
    Top = 70
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentFont = False
    TabOrder = 2
    OnClick = AddButtonClick
  end
  object DelButton: TButton
    Left = 110
    Top = 70
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentFont = False
    TabOrder = 3
    OnClick = DelButtonClick
  end
  object OutputEdit: TEdit
    Left = 24
    Top = 171
    Width = 161
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
    Text = #1042#1099#1074#1086#1076
  end
  object InputEdit: TEdit
    Left = 24
    Top = 147
    Width = 161
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    NumbersOnly = True
    ParentFont = False
    TabOrder = 5
    Text = #1050#1083#1102#1095
    OnChange = InputEditChange
    OnClick = InputEditChange
  end
  object FindButton: TButton
    Left = 110
    Top = 198
    Width = 75
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentFont = False
    TabOrder = 6
    OnClick = FindButtonClick
  end
  object MinEdit: TEdit
    Left = 24
    Top = 272
    Width = 161
    Height = 21
    ReadOnly = True
    TabOrder = 7
  end
  object MinButton: TButton
    Left = 110
    Top = 299
    Width = 75
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentFont = False
    TabOrder = 8
    OnClick = MinButtonClick
  end
end

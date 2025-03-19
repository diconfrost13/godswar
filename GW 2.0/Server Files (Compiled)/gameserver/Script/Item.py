
ITEM_TRADE_PRESTIGE=0
ITEM_TRADE_CONSORTIA_CONTRIBUTE=1
ITEM_TRADE_MONEY=2
ITEM_TRADE_BIJOU=3

class ItemData:
    def __init__(self):
        self.Base = -1
        self.BaseLv = 1
        self.Append = [-1 , -1 , -1 , -1 , -1]
        self.AppendLv = 1
        self.Overlap = 1
        self.Binding = 0
        self.Type = [ITEM_TRADE_MONEY]
        self.Consume = [-1]

    def __del__(self):
        return 0

ItemList0 = []

ItemList101=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList101[0].Base=4000
ItemList101[0].Overlap=5
ItemList101[0].Consume=[5]
ItemList101[1].Base=4001
ItemList101[1].Overlap=5
ItemList101[1].Consume=[25]
ItemList101[2].Base=4002
ItemList101[2].Overlap=5
ItemList101[2].Consume=[80]
ItemList101[3].Base=4003
ItemList101[3].Overlap=5
ItemList101[3].Consume=[200]


ItemList102=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList102[0].Base=4000
ItemList102[0].Overlap=5
ItemList102[0].Consume=[5]
ItemList102[1].Base=4001
ItemList102[1].Overlap=5
ItemList102[1].Consume=[25]
ItemList102[2].Base=4002
ItemList102[2].Overlap=5
ItemList102[2].Consume=[80]
ItemList102[3].Base=4003
ItemList102[3].Overlap=5
ItemList102[3].Consume=[200]


ItemList103=[ItemData(),ItemData()]
ItemList103[0].Base=4000
ItemList103[0].Overlap=5
ItemList103[0].Consume=[5]
ItemList103[1].Base=4001
ItemList103[1].Overlap=5
ItemList103[1].Consume=[25]


ItemList104=[ItemData(),ItemData()]
ItemList104[0].Base=4000
ItemList104[0].Overlap=5
ItemList104[0].Consume=[5]
ItemList104[1].Base=4001
ItemList104[1].Overlap=5
ItemList104[1].Consume=[25]


ItemList105=[ItemData(),ItemData()]
ItemList105[0].Base=4002
ItemList105[0].Overlap=5
ItemList105[0].Consume=[80]
ItemList105[1].Base=4003
ItemList105[1].Overlap=5
ItemList105[1].Consume=[200]


ItemList106=[ItemData(),ItemData()]
ItemList106[0].Base=4002
ItemList106[0].Overlap=5
ItemList106[0].Consume=[80]
ItemList106[1].Base=4003
ItemList106[1].Overlap=5
ItemList106[1].Consume=[200]


ItemList111=[ItemData(),ItemData()]
ItemList111[0].Base=4300
ItemList111[0].Consume=[100]
ItemList111[1].Base=4100
ItemList111[1].Consume=[60000]


ItemList112=[ItemData(),ItemData()]
ItemList112[0].Base=4304
ItemList112[0].Consume=[100]
ItemList112[1].Base=4100
ItemList112[1].Consume=[60000]


ItemList113=[ItemData()]
ItemList113[0].Base=4300
ItemList113[0].Consume=[100]


ItemList114=[ItemData()]
ItemList114[0].Base=4304
ItemList114[0].Consume=[100]


ItemList115=[ItemData()]
ItemList115[0].Base=4300
ItemList115[0].Consume=[100]


ItemList116=[ItemData()]
ItemList116[0].Base=4304
ItemList116[0].Consume=[100]


ItemList201=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList201[0].Base=1000
ItemList201[0].Consume=[58]
ItemList201[1].Base=1001
ItemList201[1].Consume=[118]
ItemList201[2].Base=1002
ItemList201[2].Consume=[205]
ItemList201[3].Base=1003
ItemList201[3].Consume=[281]
ItemList201[4].Base=1004
ItemList201[4].Consume=[345]
ItemList201[5].Base=1005
ItemList201[5].Consume=[398]
ItemList201[6].Base=1006
ItemList201[6].Consume=[450]
ItemList201[7].Base=1007
ItemList201[7].Consume=[503]
ItemList201[8].Base=1008
ItemList201[8].Consume=[555]
ItemList201[9].Base=1009
ItemList201[9].Consume=[608]
ItemList201[10].Base=1010
ItemList201[10].Consume=[660]
ItemList201[11].Base=1011
ItemList201[11].Consume=[707]
ItemList201[12].Base=1400
ItemList201[12].Consume=[58]
ItemList201[13].Base=1401
ItemList201[13].Consume=[118]
ItemList201[14].Base=1402
ItemList201[14].Consume=[205]
ItemList201[15].Base=1403
ItemList201[15].Consume=[281]
ItemList201[16].Base=1404
ItemList201[16].Consume=[345]
ItemList201[17].Base=1405
ItemList201[17].Consume=[398]
ItemList201[18].Base=1406
ItemList201[18].Consume=[450]
ItemList201[19].Base=1407
ItemList201[19].Consume=[503]
ItemList201[20].Base=1408
ItemList201[20].Consume=[555]
ItemList201[21].Base=1409
ItemList201[21].Consume=[608]
ItemList201[22].Base=1410
ItemList201[22].Consume=[660]
ItemList201[23].Base=1411
ItemList201[23].Consume=[707]


ItemList202=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList202[0].Base=1000
ItemList202[0].Consume=[58]
ItemList202[1].Base=1001
ItemList202[1].Consume=[118]
ItemList202[2].Base=1002
ItemList202[2].Consume=[205]
ItemList202[3].Base=1003
ItemList202[3].Consume=[281]
ItemList202[4].Base=1004
ItemList202[4].Consume=[345]
ItemList202[5].Base=1400
ItemList202[5].Consume=[58]
ItemList202[6].Base=1401
ItemList202[6].Consume=[118]
ItemList202[7].Base=1402
ItemList202[7].Consume=[205]
ItemList202[8].Base=1403
ItemList202[8].Consume=[281]
ItemList202[9].Base=1404
ItemList202[9].Consume=[345]


ItemList203=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList203[0].Base=1005
ItemList203[0].Consume=[398]
ItemList203[1].Base=1006
ItemList203[1].Consume=[450]
ItemList203[2].Base=1007
ItemList203[2].Consume=[503]
ItemList203[3].Base=1008
ItemList203[3].Consume=[555]
ItemList203[4].Base=1405
ItemList203[4].Consume=[398]
ItemList203[5].Base=1406
ItemList203[5].Consume=[450]
ItemList203[6].Base=1407
ItemList203[6].Consume=[503]
ItemList203[7].Base=1408
ItemList203[7].Consume=[555]


ItemList211=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList211[0].Base=2300
ItemList211[0].Consume=[71]
ItemList211[1].Base=2301
ItemList211[1].Consume=[217]
ItemList211[2].Base=2302
ItemList211[2].Consume=[357]
ItemList211[3].Base=2303
ItemList211[3].Consume=[479]
ItemList211[4].Base=2304
ItemList211[4].Consume=[596]
ItemList211[5].Base=2305
ItemList211[5].Consume=[648]
ItemList211[6].Base=2306
ItemList211[6].Consume=[695]
ItemList211[7].Base=2500
ItemList211[7].Consume=[71]
ItemList211[8].Base=2501
ItemList211[8].Consume=[217]
ItemList211[9].Base=2502
ItemList211[9].Consume=[357]
ItemList211[10].Base=2503
ItemList211[10].Consume=[479]
ItemList211[11].Base=2504
ItemList211[11].Consume=[596]
ItemList211[12].Base=2505
ItemList211[12].Consume=[648]
ItemList211[13].Base=2506
ItemList211[13].Consume=[695]


ItemList212=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList212[0].Base=2300
ItemList212[0].Consume=[71]
ItemList212[1].Base=2301
ItemList212[1].Consume=[217]
ItemList212[2].Base=2500
ItemList212[2].Consume=[71]
ItemList212[3].Base=2501
ItemList212[3].Consume=[217]


ItemList213=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList213[0].Base=2302
ItemList213[0].Consume=[357]
ItemList213[1].Base=2303
ItemList213[1].Consume=[479]
ItemList213[2].Base=2304
ItemList213[2].Consume=[596]
ItemList213[3].Base=2502
ItemList213[3].Consume=[357]
ItemList213[4].Base=2503
ItemList213[4].Consume=[479]
ItemList213[5].Base=2504
ItemList213[5].Consume=[596]


ItemList221=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList221[0].Base=2100
ItemList221[0].Consume=[58]
ItemList221[1].Base=2101
ItemList221[1].Consume=[118]
ItemList221[2].Base=2102
ItemList221[2].Consume=[205]
ItemList221[3].Base=2103
ItemList221[3].Consume=[281]
ItemList221[4].Base=2104
ItemList221[4].Consume=[345]
ItemList221[5].Base=2105
ItemList221[5].Consume=[398]
ItemList221[6].Base=2106
ItemList221[6].Consume=[450]
ItemList221[7].Base=2107
ItemList221[7].Consume=[503]
ItemList221[8].Base=2108
ItemList221[8].Consume=[555]
ItemList221[9].Base=2109
ItemList221[9].Consume=[608]
ItemList221[10].Base=2110
ItemList221[10].Consume=[660]
ItemList221[11].Base=2111
ItemList221[11].Consume=[707]


ItemList222=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList222[0].Base=2100
ItemList222[0].Consume=[58]
ItemList222[1].Base=2101
ItemList222[1].Consume=[118]
ItemList222[2].Base=2102
ItemList222[2].Consume=[205]
ItemList222[3].Base=2103
ItemList222[3].Consume=[281]
ItemList222[4].Base=2104
ItemList222[4].Consume=[345]


ItemList223=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList223[0].Base=2105
ItemList223[0].Consume=[398]
ItemList223[1].Base=2106
ItemList223[1].Consume=[450]
ItemList223[2].Base=2107
ItemList223[2].Consume=[503]
ItemList223[3].Base=2108
ItemList223[3].Consume=[555]


ItemList231=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList231[0].Base=3000
ItemList231[0].Consume=[71]
ItemList231[1].Base=3001
ItemList231[1].Consume=[217]
ItemList231[2].Base=3002
ItemList231[2].Consume=[357]
ItemList231[3].Base=3003
ItemList231[3].Consume=[479]
ItemList231[4].Base=3004
ItemList231[4].Consume=[596]
ItemList231[5].Base=3005
ItemList231[5].Consume=[648]
ItemList231[6].Base=3006
ItemList231[6].Consume=[695]


ItemList232=[ItemData(),ItemData()]
ItemList232[0].Base=3000
ItemList232[0].Consume=[71]
ItemList232[1].Base=3001
ItemList232[1].Consume=[217]


ItemList233=[ItemData(),ItemData(),ItemData()]
ItemList233[0].Base=3002
ItemList233[0].Consume=[357]
ItemList233[1].Base=3003
ItemList233[1].Consume=[479]
ItemList233[2].Base=3004
ItemList233[2].Consume=[596]


ItemList301=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList301[0].Base=1700
ItemList301[0].Consume=[58]
ItemList301[1].Base=1701
ItemList301[1].Consume=[118]
ItemList301[2].Base=1702
ItemList301[2].Consume=[205]
ItemList301[3].Base=1703
ItemList301[3].Consume=[281]
ItemList301[4].Base=1704
ItemList301[4].Consume=[345]
ItemList301[5].Base=1705
ItemList301[5].Consume=[398]
ItemList301[6].Base=1706
ItemList301[6].Consume=[450]
ItemList301[7].Base=1707
ItemList301[7].Consume=[503]
ItemList301[8].Base=1708
ItemList301[8].Consume=[555]
ItemList301[9].Base=1709
ItemList301[9].Consume=[608]
ItemList301[10].Base=1710
ItemList301[10].Consume=[660]
ItemList301[11].Base=1711
ItemList301[11].Consume=[707]
ItemList301[12].Base=1800
ItemList301[12].Consume=[58]
ItemList301[13].Base=1801
ItemList301[13].Consume=[118]
ItemList301[14].Base=1802
ItemList301[14].Consume=[205]
ItemList301[15].Base=1803
ItemList301[15].Consume=[281]
ItemList301[16].Base=1804
ItemList301[16].Consume=[345]
ItemList301[17].Base=1805
ItemList301[17].Consume=[398]
ItemList301[18].Base=1806
ItemList301[18].Consume=[450]
ItemList301[19].Base=1807
ItemList301[19].Consume=[503]
ItemList301[20].Base=1808
ItemList301[20].Consume=[555]
ItemList301[21].Base=1809
ItemList301[21].Consume=[608]
ItemList301[22].Base=1810
ItemList301[22].Consume=[660]
ItemList301[23].Base=1811
ItemList301[23].Consume=[707]


ItemList302=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList302[0].Base=1700
ItemList302[0].Consume=[58]
ItemList302[1].Base=1701
ItemList302[1].Consume=[118]
ItemList302[2].Base=1702
ItemList302[2].Consume=[205]
ItemList302[3].Base=1703
ItemList302[3].Consume=[281]
ItemList302[4].Base=1704
ItemList302[4].Consume=[345]
ItemList302[5].Base=1800
ItemList302[5].Consume=[58]
ItemList302[6].Base=1801
ItemList302[6].Consume=[118]
ItemList302[7].Base=1802
ItemList302[7].Consume=[205]
ItemList302[8].Base=1803
ItemList302[8].Consume=[281]
ItemList302[9].Base=1804
ItemList302[9].Consume=[345]


ItemList303=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList303[0].Base=1705
ItemList303[0].Consume=[398]
ItemList303[1].Base=1706
ItemList303[1].Consume=[450]
ItemList303[2].Base=1707
ItemList303[2].Consume=[503]
ItemList303[3].Base=1708
ItemList303[3].Consume=[555]
ItemList303[4].Base=1805
ItemList303[4].Consume=[398]
ItemList303[5].Base=1806
ItemList303[5].Consume=[450]
ItemList303[6].Base=1807
ItemList303[6].Consume=[503]
ItemList303[7].Base=1808
ItemList303[7].Consume=[555]


ItemList311=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList311[0].Base=2400
ItemList311[0].Consume=[71]
ItemList311[1].Base=2401
ItemList311[1].Consume=[217]
ItemList311[2].Base=2402
ItemList311[2].Consume=[357]
ItemList311[3].Base=2403
ItemList311[3].Consume=[479]
ItemList311[4].Base=2404
ItemList311[4].Consume=[596]
ItemList311[5].Base=2405
ItemList311[5].Consume=[648]
ItemList311[6].Base=2406
ItemList311[6].Consume=[695]
ItemList311[7].Base=2500
ItemList311[7].Consume=[77]
ItemList311[8].Base=2501
ItemList311[8].Consume=[223]
ItemList311[9].Base=2502
ItemList311[9].Consume=[363]
ItemList311[10].Base=2503
ItemList311[10].Consume=[485]
ItemList311[11].Base=2504
ItemList311[11].Consume=[602]
ItemList311[12].Base=2505
ItemList311[12].Consume=[654]
ItemList311[13].Base=2506
ItemList311[13].Consume=[701]


ItemList312=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList312[0].Base=2400
ItemList312[0].Consume=[71]
ItemList312[1].Base=2401
ItemList312[1].Consume=[217]
ItemList312[2].Base=2500
ItemList312[2].Consume=[77]
ItemList312[3].Base=2501
ItemList312[3].Consume=[223]


ItemList313=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList313[0].Base=2402
ItemList313[0].Consume=[357]
ItemList313[1].Base=2403
ItemList313[1].Consume=[479]
ItemList313[2].Base=2404
ItemList313[2].Consume=[596]
ItemList313[3].Base=2502
ItemList313[3].Consume=[363]
ItemList313[4].Base=2503
ItemList313[4].Consume=[485]
ItemList313[5].Base=2504
ItemList313[5].Consume=[602]


ItemList321=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList321[0].Base=2200
ItemList321[0].Consume=[58]
ItemList321[1].Base=2201
ItemList321[1].Consume=[118]
ItemList321[2].Base=2202
ItemList321[2].Consume=[205]
ItemList321[3].Base=2203
ItemList321[3].Consume=[281]
ItemList321[4].Base=2204
ItemList321[4].Consume=[345]
ItemList321[5].Base=2205
ItemList321[5].Consume=[398]
ItemList321[6].Base=2206
ItemList321[6].Consume=[450]
ItemList321[7].Base=2207
ItemList321[7].Consume=[503]
ItemList321[8].Base=2208
ItemList321[8].Consume=[555]
ItemList321[9].Base=2209
ItemList321[9].Consume=[608]
ItemList321[10].Base=2210
ItemList321[10].Consume=[660]
ItemList321[11].Base=2211
ItemList321[11].Consume=[707]


ItemList322=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList322[0].Base=2200
ItemList322[0].Consume=[58]
ItemList322[1].Base=2201
ItemList322[1].Consume=[118]
ItemList322[2].Base=2202
ItemList322[2].Consume=[205]
ItemList322[3].Base=2203
ItemList322[3].Consume=[281]
ItemList322[4].Base=2204
ItemList322[4].Consume=[345]


ItemList323=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList323[0].Base=2205
ItemList323[0].Consume=[398]
ItemList323[1].Base=2206
ItemList323[1].Consume=[450]
ItemList323[2].Base=2207
ItemList323[2].Consume=[503]
ItemList323[3].Base=2208
ItemList323[3].Consume=[555]


ItemList331=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList331[0].Base=3000
ItemList331[0].Consume=[71]
ItemList331[1].Base=3001
ItemList331[1].Consume=[217]
ItemList331[2].Base=3002
ItemList331[2].Consume=[357]
ItemList331[3].Base=3003
ItemList331[3].Consume=[479]
ItemList331[4].Base=3004
ItemList331[4].Consume=[596]
ItemList331[5].Base=3005
ItemList331[5].Consume=[648]
ItemList331[6].Base=3006
ItemList331[6].Consume=[695]


ItemList332=[ItemData(),ItemData()]
ItemList332[0].Base=3000
ItemList332[0].Consume=[71]
ItemList332[1].Base=3001
ItemList332[1].Consume=[217]


ItemList333=[ItemData(),ItemData(),ItemData()]
ItemList333[0].Base=3002
ItemList333[0].Consume=[357]
ItemList333[1].Base=3003
ItemList333[1].Consume=[479]
ItemList333[2].Base=3004
ItemList333[2].Consume=[596]


ItemList401=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList401[0].Base=2700
ItemList401[0].Consume=[77]
ItemList401[1].Base=2701
ItemList401[1].Consume=[223]
ItemList401[2].Base=2702
ItemList401[2].Consume=[363]
ItemList401[3].Base=2703
ItemList401[3].Consume=[485]
ItemList401[4].Base=2704
ItemList401[4].Consume=[602]
ItemList401[5].Base=2705
ItemList401[5].Consume=[654]
ItemList401[6].Base=2706
ItemList401[6].Consume=[701]


ItemList402=[ItemData(),ItemData()]
ItemList402[0].Base=2700
ItemList402[0].Consume=[77]
ItemList402[1].Base=2701
ItemList402[1].Consume=[223]


ItemList403=[ItemData(),ItemData(),ItemData()]
ItemList403[0].Base=2702
ItemList403[0].Consume=[363]
ItemList403[1].Base=2703
ItemList403[1].Consume=[485]
ItemList403[2].Base=2704
ItemList403[2].Consume=[602]


ItemList411=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList411[0].Base=2000
ItemList411[0].Consume=[58]
ItemList411[1].Base=2001
ItemList411[1].Consume=[118]
ItemList411[2].Base=2002
ItemList411[2].Consume=[205]
ItemList411[3].Base=2003
ItemList411[3].Consume=[281]
ItemList411[4].Base=2004
ItemList411[4].Consume=[345]
ItemList411[5].Base=2005
ItemList411[5].Consume=[398]
ItemList411[6].Base=2006
ItemList411[6].Consume=[450]
ItemList411[7].Base=2007
ItemList411[7].Consume=[503]
ItemList411[8].Base=2008
ItemList411[8].Consume=[555]
ItemList411[9].Base=2009
ItemList411[9].Consume=[608]
ItemList411[10].Base=2010
ItemList411[10].Consume=[660]
ItemList411[11].Base=2011
ItemList411[11].Consume=[707]


ItemList412=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList412[0].Base=2000
ItemList412[0].Consume=[58]
ItemList412[1].Base=2001
ItemList412[1].Consume=[118]
ItemList412[2].Base=2002
ItemList412[2].Consume=[205]
ItemList412[3].Base=2003
ItemList412[3].Consume=[281]
ItemList412[4].Base=2004
ItemList412[4].Consume=[345]


ItemList413=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList413[0].Base=2005
ItemList413[0].Consume=[398]
ItemList413[1].Base=2006
ItemList413[1].Consume=[450]
ItemList413[2].Base=2007
ItemList413[2].Consume=[503]
ItemList413[3].Base=2008
ItemList413[3].Consume=[555]


ItemList421=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList421[0].Base=2800
ItemList421[0].Consume=[64]
ItemList421[1].Base=2801
ItemList421[1].Consume=[123]
ItemList421[2].Base=2802
ItemList421[2].Consume=[211]
ItemList421[3].Base=2803
ItemList421[3].Consume=[287]
ItemList421[4].Base=2804
ItemList421[4].Consume=[351]
ItemList421[5].Base=2805
ItemList421[5].Consume=[403]
ItemList421[6].Base=2806
ItemList421[6].Consume=[456]
ItemList421[7].Base=2807
ItemList421[7].Consume=[508]
ItemList421[8].Base=2808
ItemList421[8].Consume=[561]
ItemList421[9].Base=2809
ItemList421[9].Consume=[613]
ItemList421[10].Base=2810
ItemList421[10].Consume=[666]
ItemList421[11].Base=2811
ItemList421[11].Consume=[713]


ItemList422=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList422[0].Base=2800
ItemList422[0].Consume=[64]
ItemList422[1].Base=2801
ItemList422[1].Consume=[123]
ItemList422[2].Base=2802
ItemList422[2].Consume=[211]
ItemList422[3].Base=2803
ItemList422[3].Consume=[287]


ItemList423=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList423[0].Base=2804
ItemList423[0].Consume=[351]
ItemList423[1].Base=2805
ItemList423[1].Consume=[403]
ItemList423[2].Base=2806
ItemList423[2].Consume=[456]
ItemList423[3].Base=2807
ItemList423[3].Consume=[508]
ItemList423[4].Base=2808


ItemList431=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList431[0].Base=2900
ItemList431[0].Consume=[64]
ItemList431[1].Base=2901
ItemList431[1].Consume=[123]
ItemList431[2].Base=2902
ItemList431[2].Consume=[211]
ItemList431[3].Base=2903
ItemList431[3].Consume=[287]
ItemList431[4].Base=2904
ItemList431[4].Consume=[351]
ItemList431[5].Base=2905
ItemList431[5].Consume=[403]
ItemList431[6].Base=2906
ItemList431[6].Consume=[456]
ItemList431[7].Base=2907
ItemList431[7].Consume=[508]
ItemList431[8].Base=2908
ItemList431[8].Consume=[561]
ItemList431[9].Base=2909
ItemList431[9].Consume=[613]
ItemList431[10].Base=2910
ItemList431[10].Consume=[666]
ItemList431[11].Base=2911
ItemList431[11].Consume=[713]


ItemList432=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList432[0].Base=2900
ItemList432[0].Consume=[64]
ItemList432[1].Base=2901
ItemList432[1].Consume=[123]
ItemList432[2].Base=2902
ItemList432[2].Consume=[211]
ItemList432[3].Base=2903
ItemList432[3].Consume=[287]


ItemList433=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList433[0].Base=2904
ItemList433[0].Consume=[351]
ItemList433[1].Base=2905
ItemList433[1].Consume=[403]
ItemList433[2].Base=2906
ItemList433[2].Consume=[456]
ItemList433[3].Base=2907
ItemList433[3].Consume=[508]
ItemList433[4].Base=2908
ItemList433[4].Consume=[561]


ItemList501=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList501[0].Base=5419
ItemList501[0].Consume=[496]
ItemList501[1].Base=5411
ItemList501[1].Consume=[976]
ItemList501[2].Base=5427
ItemList501[2].Consume=[976]
ItemList501[3].Base=5437
ItemList501[3].Consume=[976]
ItemList501[4].Base=5400
ItemList501[4].Consume=[1456]
ItemList501[5].Base=5420
ItemList501[5].Consume=[2416]
ItemList501[6].Base=5442
ItemList501[6].Consume=[2512]
ItemList501[7].Base=5412
ItemList501[7].Consume=[2896]
ItemList501[8].Base=5432
ItemList501[8].Consume=[2896]
ItemList501[9].Base=5428
ItemList501[9].Consume=[3280]
ItemList501[10].Base=5438
ItemList501[10].Consume=[3280]
ItemList501[11].Base=5403
ItemList501[11].Consume=[3856]
ItemList501[12].Base=5433
ItemList501[12].Consume=[5008]
ItemList501[13].Base=5404
ItemList501[13].Consume=[5296]
ItemList501[14].Base=5423
ItemList501[14].Consume=[5296]
ItemList501[15].Base=5429
ItemList501[15].Consume=[10096]
ItemList501[16].Base=5439
ItemList501[16].Consume=[5584]
ItemList501[17].Base=5415
ItemList501[17].Consume=[5776]
ItemList501[18].Base=5434
ItemList501[18].Consume=[7120]
ItemList501[19].Base=5407
ItemList501[19].Consume=[7216]
ItemList501[20].Base=5424
ItemList501[20].Consume=[7216]
ItemList501[21].Base=5416
ItemList501[21].Consume=[7696]
ItemList501[22].Base=5408
ItemList501[22].Consume=[8656]


ItemList502=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList502[0].Base=5419
ItemList502[0].Consume=[496]
ItemList502[1].Base=5411
ItemList502[1].Consume=[976]
ItemList502[2].Base=5427
ItemList502[2].Consume=[976]
ItemList502[3].Base=5437
ItemList502[3].Consume=[976]
ItemList502[4].Base=5400
ItemList502[4].Consume=[1456]
ItemList502[5].Base=5420
ItemList502[5].Consume=[2416]
ItemList502[6].Base=5442
ItemList502[6].Consume=[2512]
ItemList502[7].Base=5412
ItemList502[7].Consume=[2896]
ItemList502[8].Base=5432
ItemList502[8].Consume=[2896]
ItemList502[9].Base=5428
ItemList502[9].Consume=[3280]
ItemList502[10].Base=5438
ItemList502[10].Consume=[3280]
ItemList502[11].Base=5403
ItemList502[11].Consume=[3856]


ItemList503=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList503[0].Base=5433
ItemList503[0].Consume=[5008]
ItemList503[1].Base=5404
ItemList503[1].Consume=[5296]
ItemList503[2].Base=5423
ItemList503[2].Consume=[5296]
ItemList503[3].Base=5429
ItemList503[3].Consume=[10096]
ItemList503[4].Base=5439
ItemList503[4].Consume=[5584]
ItemList503[5].Base=5415
ItemList503[5].Consume=[5776]
ItemList503[6].Base=5434
ItemList503[6].Consume=[7120]
ItemList503[7].Base=5407
ItemList503[7].Consume=[7216]
ItemList503[8].Base=5424
ItemList503[8].Consume=[7216]
ItemList503[9].Base=5416
ItemList503[9].Consume=[7696]
ItemList503[10].Base=5408
ItemList503[10].Consume=[8656]


ItemList511=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList511[0].Base=5642
ItemList511[0].Consume=[496]
ItemList511[1].Base=5600
ItemList511[1].Consume=[592]
ItemList511[2].Base=5630
ItemList511[2].Consume=[784]
ItemList511[3].Base=5605
ItemList511[3].Consume=[976]
ItemList511[4].Base=5615
ItemList511[4].Consume=[976]
ItemList511[5].Base=5610
ItemList511[5].Consume=[1360]
ItemList511[6].Base=5623
ItemList511[6].Consume=[1936]
ItemList511[7].Base=5631
ItemList511[7].Consume=[2128]
ItemList511[8].Base=5643
ItemList511[8].Consume=[2416]
ItemList511[9].Base=5620
ItemList511[9].Consume=[2512]
ItemList511[10].Base=5601
ItemList511[10].Consume=[3280]
ItemList511[11].Base=5616
ItemList511[11].Consume=[3280]
ItemList511[12].Base=5606
ItemList511[12].Consume=[3664]
ItemList511[13].Base=5611
ItemList511[13].Consume=[3856]
ItemList511[14].Base=5634
ItemList511[14].Consume=[4048]
ItemList511[15].Base=5646
ItemList511[15].Consume=[5296]
ItemList511[16].Base=5635
ItemList511[16].Consume=[5488]
ItemList511[17].Base=5617
ItemList511[17].Consume=[5584]
ItemList511[18].Base=5602
ItemList511[18].Consume=[5968]
ItemList511[19].Base=5626
ItemList511[19].Consume=[6256]
ItemList511[20].Base=5607
ItemList511[20].Consume=[6352]
ItemList511[21].Base=5612
ItemList511[21].Consume=[6352]
ItemList511[22].Base=5638
ItemList511[22].Consume=[7216]
ItemList511[23].Base=5647
ItemList511[23].Consume=[7216]
ItemList511[24].Base=5627
ItemList511[24].Consume=[7696]
ItemList511[25].Base=5639
ItemList511[25].Consume=[8656]


ItemList512=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList512[0].Base=5642
ItemList512[0].Consume=[496]
ItemList512[1].Base=5600
ItemList512[1].Consume=[592]
ItemList512[2].Base=5630
ItemList512[2].Consume=[784]
ItemList512[3].Base=5605
ItemList512[3].Consume=[976]
ItemList512[4].Base=5615
ItemList512[4].Consume=[976]
ItemList512[5].Base=5610
ItemList512[5].Consume=[1360]
ItemList512[6].Base=5623
ItemList512[6].Consume=[1936]
ItemList512[7].Base=5631
ItemList512[7].Consume=[2128]
ItemList512[8].Base=5643
ItemList512[8].Consume=[2416]
ItemList512[9].Base=5620
ItemList512[9].Consume=[2512]
ItemList512[10].Base=5601
ItemList512[10].Consume=[3280]
ItemList512[11].Base=5616
ItemList512[11].Consume=[3280]
ItemList512[12].Base=5606
ItemList512[12].Consume=[3664]
ItemList512[13].Base=5611
ItemList512[13].Consume=[3856]
ItemList512[14].Base=5634
ItemList512[14].Consume=[4048]


ItemList513=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList513[0].Base=5646
ItemList513[0].Consume=[5296]
ItemList513[1].Base=5635
ItemList513[1].Consume=[5488]
ItemList513[2].Base=5617
ItemList513[2].Consume=[5584]
ItemList513[3].Base=5602
ItemList513[3].Consume=[5968]
ItemList513[4].Base=5626
ItemList513[4].Consume=[6256]
ItemList513[5].Base=5607
ItemList513[5].Consume=[6352]
ItemList513[6].Base=5612
ItemList513[6].Consume=[6352]
ItemList513[7].Base=5638
ItemList513[7].Consume=[7216]
ItemList513[8].Base=5647
ItemList513[8].Consume=[7216]
ItemList513[9].Base=5627
ItemList513[9].Consume=[7696]
ItemList513[10].Base=5639
ItemList513[10].Consume=[8656]


ItemList521=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList521[0].Base=5019
ItemList521[0].Consume=[496]
ItemList521[1].Base=5011
ItemList521[1].Consume=[976]
ItemList521[2].Base=5037
ItemList521[2].Consume=[976]
ItemList521[3].Base=5027
ItemList521[3].Consume=[1360]
ItemList521[4].Base=5000
ItemList521[4].Consume=[1456]
ItemList521[5].Base=5032
ItemList521[5].Consume=[1936]
ItemList521[6].Base=5020
ItemList521[6].Consume=[2416]
ItemList521[7].Base=5012
ItemList521[7].Consume=[2896]
ItemList521[8].Base=5038
ItemList521[8].Consume=[3280]
ItemList521[9].Base=5003
ItemList521[9].Consume=[3856]
ItemList521[10].Base=5028
ItemList521[10].Consume=[3856]
ItemList521[11].Base=5033
ItemList521[11].Consume=[4048]
ItemList521[12].Base=5023
ItemList521[12].Consume=[4816]
ItemList521[13].Base=5004
ItemList521[13].Consume=[5296]
ItemList521[14].Base=5039
ItemList521[14].Consume=[5584]
ItemList521[15].Base=5015
ItemList521[15].Consume=[5776]
ItemList521[16].Base=5034
ItemList521[16].Consume=[6160]
ItemList521[17].Base=5029
ItemList521[17].Consume=[6352]
ItemList521[18].Base=5024
ItemList521[18].Consume=[6736]
ItemList521[19].Base=5007
ItemList521[19].Consume=[7216]
ItemList521[20].Base=5016
ItemList521[20].Consume=[7696]
ItemList521[21].Base=5008
ItemList521[21].Consume=[8656]


ItemList522=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList522[0].Base=5019
ItemList522[0].Consume=[496]
ItemList522[1].Base=5011
ItemList522[1].Consume=[976]
ItemList522[2].Base=5037
ItemList522[2].Consume=[976]
ItemList522[3].Base=5027
ItemList522[3].Consume=[1360]
ItemList522[4].Base=5000
ItemList522[4].Consume=[1456]
ItemList522[5].Base=5032
ItemList522[5].Consume=[1936]
ItemList522[6].Base=5020
ItemList522[6].Consume=[2416]
ItemList522[7].Base=5012
ItemList522[7].Consume=[2896]
ItemList522[8].Base=5038
ItemList522[8].Consume=[3280]
ItemList522[9].Base=5003
ItemList522[9].Consume=[3856]
ItemList522[10].Base=5028
ItemList522[10].Consume=[3856]
ItemList522[11].Base=5033
ItemList522[11].Consume=[4048]
ItemList522[12].Base=5023
ItemList522[12].Consume=[4816]


ItemList523=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList523[0].Base=5004
ItemList523[0].Consume=[5296]
ItemList523[1].Base=5039
ItemList523[1].Consume=[5584]
ItemList523[2].Base=5015
ItemList523[2].Consume=[5776]
ItemList523[3].Base=5034
ItemList523[3].Consume=[6160]
ItemList523[4].Base=5029
ItemList523[4].Consume=[6352]
ItemList523[5].Base=5024
ItemList523[5].Consume=[6736]
ItemList523[6].Base=5007
ItemList523[6].Consume=[7216]
ItemList523[7].Base=5016
ItemList523[7].Consume=[7696]
ItemList523[8].Base=5008
ItemList523[8].Consume=[8656]


ItemList531=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList531[0].Base=5219
ItemList531[0].Consume=[496]
ItemList531[1].Base=5211
ItemList531[1].Consume=[976]
ItemList531[2].Base=5235
ItemList531[2].Consume=[976]
ItemList531[3].Base=5240
ItemList531[3].Consume=[1360]
ItemList531[4].Base=5200
ItemList531[4].Consume=[1456]
ItemList531[5].Base=5227
ItemList531[5].Consume=[1456]
ItemList531[6].Base=5220
ItemList531[6].Consume=[2416]
ItemList531[7].Base=5212
ItemList531[7].Consume=[2896]
ItemList531[8].Base=5228
ItemList531[8].Consume=[2896]
ItemList531[9].Base=5236
ItemList531[9].Consume=[3280]
ItemList531[10].Base=5203
ItemList531[10].Consume=[3856]
ItemList531[11].Base=5241
ItemList531[11].Consume=[3856]
ItemList531[12].Base=5231
ItemList531[12].Consume=[4816]
ItemList531[13].Base=5204
ItemList531[13].Consume=[5296]
ItemList531[14].Base=5223
ItemList531[14].Consume=[5296]
ItemList531[15].Base=5237
ItemList531[15].Consume=[5584]
ItemList531[16].Base=5215
ItemList531[16].Consume=[5776]
ItemList531[17].Base=5242
ItemList531[17].Consume=[6352]
ItemList531[18].Base=5232
ItemList531[18].Consume=[6736]
ItemList531[19].Base=5207
ItemList531[19].Consume=[7216]
ItemList531[20].Base=5224
ItemList531[20].Consume=[7216]
ItemList531[21].Base=5216
ItemList531[21].Consume=[7696]
ItemList531[22].Base=5208
ItemList531[22].Consume=[8656]


ItemList532=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList532[0].Base=5219
ItemList532[0].Consume=[496]
ItemList532[1].Base=5211
ItemList532[1].Consume=[976]
ItemList532[2].Base=5235
ItemList532[2].Consume=[976]
ItemList532[3].Base=5240
ItemList532[3].Consume=[1360]
ItemList532[4].Base=5200
ItemList532[4].Consume=[1456]
ItemList532[5].Base=5227
ItemList532[5].Consume=[1456]
ItemList532[6].Base=5220
ItemList532[6].Consume=[2416]
ItemList532[7].Base=5212
ItemList532[7].Consume=[2896]
ItemList532[8].Base=5228
ItemList532[8].Consume=[2896]
ItemList532[9].Base=5236
ItemList532[9].Consume=[3280]
ItemList532[10].Base=5203
ItemList532[10].Consume=[3856]
ItemList532[11].Base=5241
ItemList532[11].Consume=[3856]
ItemList532[12].Base=5231
ItemList532[12].Consume=[4816]


ItemList533=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList533[0].Base=5204
ItemList533[0].Consume=[5296]
ItemList533[1].Base=5223
ItemList533[1].Consume=[5296]
ItemList533[2].Base=5237
ItemList533[2].Consume=[5584]
ItemList533[3].Base=5215
ItemList533[3].Consume=[5776]
ItemList533[4].Base=5242
ItemList533[4].Consume=[6352]
ItemList533[5].Base=5232
ItemList533[5].Consume=[6736]
ItemList533[6].Base=5207
ItemList533[6].Consume=[7216]
ItemList533[7].Base=5224
ItemList533[7].Consume=[7216]
ItemList533[8].Base=5216
ItemList533[8].Consume=[7696]
ItemList533[9].Base=5208
ItemList533[9].Consume=[8656]


ItemList601=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList601[0].Base=3100
ItemList601[0].Consume=[77]
ItemList601[1].Base=3101
ItemList601[1].Consume=[223]
ItemList601[2].Base=3102
ItemList601[2].Consume=[363]
ItemList601[3].Base=3103
ItemList601[3].Consume=[485]
ItemList601[4].Base=3104
ItemList601[4].Consume=[602]
ItemList601[5].Base=3105
ItemList601[5].Consume=[654]
ItemList601[6].Base=3106
ItemList601[6].Consume=[701]


ItemList602=[ItemData(),ItemData(),ItemData()]
ItemList602[0].Base=3100
ItemList602[0].Consume=[77]
ItemList602[1].Base=3101
ItemList602[1].Consume=[223]
ItemList602[2].Base=3102
ItemList602[2].Consume=[363]


ItemList603=[ItemData(),ItemData()]
ItemList603[0].Base=3103
ItemList603[0].Consume=[485]
ItemList603[1].Base=3104
ItemList603[1].Consume=[602]


ItemList611=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList611[0].Base=3200
ItemList611[0].Consume=[71]
ItemList611[1].Base=3201
ItemList611[1].Consume=[135]
ItemList611[2].Base=3202
ItemList611[2].Consume=[199]
ItemList611[3].Base=3203
ItemList611[3].Consume=[263]
ItemList611[4].Base=3204
ItemList611[4].Consume=[328]
ItemList611[5].Base=3205
ItemList611[5].Consume=[392]
ItemList611[6].Base=3206
ItemList611[6].Consume=[456]
ItemList611[7].Base=3207
ItemList611[7].Consume=[520]
ItemList611[8].Base=3208
ItemList611[8].Consume=[584]
ItemList611[9].Base=3209
ItemList611[9].Consume=[648]
ItemList611[10].Base=3210
ItemList611[10].Consume=[713]


ItemList612=[ItemData(),ItemData(),ItemData(),ItemData()]
ItemList612[0].Base=3200
ItemList612[0].Consume=[71]
ItemList612[1].Base=3201
ItemList612[1].Consume=[135]
ItemList612[2].Base=3202
ItemList612[2].Consume=[199]
ItemList612[3].Base=3203
ItemList612[3].Consume=[263]


ItemList613=[ItemData(),ItemData()]
ItemList613[0].Base=3204
ItemList613[0].Consume=[328]
ItemList613[1].Base=3205
ItemList613[1].Consume=[392]


ItemList621=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList621[0].Base=2600
ItemList621[0].Consume=[77]
ItemList621[1].Base=2601
ItemList621[1].Consume=[223]
ItemList621[2].Base=2602
ItemList621[2].Consume=[363]
ItemList621[3].Base=2603
ItemList621[3].Consume=[485]
ItemList621[4].Base=2604
ItemList621[4].Consume=[602]
ItemList621[5].Base=2605
ItemList621[5].Consume=[654]
ItemList621[6].Base=2606
ItemList621[6].Consume=[701]


ItemList622=[ItemData(),ItemData()]
ItemList622[0].Base=2600
ItemList622[0].Consume=[77]
ItemList622[1].Base=2601
ItemList622[1].Consume=[223]


ItemList623=[ItemData(),ItemData(),ItemData()]
ItemList623[0].Base=2602
ItemList623[0].Consume=[363]
ItemList623[1].Base=2603
ItemList623[1].Consume=[485]
ItemList623[2].Base=2604
ItemList623[2].Consume=[602]


ItemList1000=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList1000[0].Base=4420
ItemList1000[0].Type=[ITEM_TRADE_BIJOU]
ItemList1000[0].Consume=[100]
ItemList1000[1].Base=4421
ItemList1000[1].Type=[ITEM_TRADE_BIJOU]
ItemList1000[1].Consume=[200]
ItemList1000[2].Base=4422
ItemList1000[2].Type=[ITEM_TRADE_BIJOU]
ItemList1000[2].Consume=[300]
ItemList1000[3].Base=4400
ItemList1000[3].Type=[ITEM_TRADE_BIJOU]
ItemList1000[3].Consume=[500]
ItemList1000[4].Base=4401
ItemList1000[4].Type=[ITEM_TRADE_BIJOU]
ItemList1000[4].Consume=[500]
ItemList1000[5].Base=4402
ItemList1000[5].Type=[ITEM_TRADE_BIJOU]
ItemList1000[5].Consume=[500]
ItemList1000[6].Base=4403
ItemList1000[6].Type=[ITEM_TRADE_BIJOU]
ItemList1000[6].Consume=[500]
ItemList1000[7].Base=4406
ItemList1000[7].Type=[ITEM_TRADE_BIJOU]
ItemList1000[7].Consume=[500]
ItemList1000[8].Base=4407
ItemList1000[8].Type=[ITEM_TRADE_BIJOU]
ItemList1000[8].Consume=[500]
ItemList1000[9].Base=4408
ItemList1000[9].Type=[ITEM_TRADE_BIJOU]
ItemList1000[9].Consume=[500]
ItemList1000[10].Base=4412
ItemList1000[10].Type=[ITEM_TRADE_BIJOU]
ItemList1000[10].Consume=[500]
ItemList1000[11].Base=4413
ItemList1000[11].Type=[ITEM_TRADE_BIJOU]
ItemList1000[11].Consume=[500]


ItemList1001=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList1001[0].Base=4420
ItemList1001[0].Type=[ITEM_TRADE_BIJOU]
ItemList1001[0].Consume=[100]
ItemList1001[1].Base=4421
ItemList1001[1].Type=[ITEM_TRADE_BIJOU]
ItemList1001[1].Consume=[200]
ItemList1001[2].Base=4422
ItemList1001[2].Type=[ITEM_TRADE_BIJOU]
ItemList1001[2].Consume=[300]
ItemList1001[3].Base=4302
ItemList1001[3].Type=[ITEM_TRADE_BIJOU]
ItemList1001[3].Consume=[500]
ItemList1001[4].Base=4303
ItemList1001[4].Type=[ITEM_TRADE_BIJOU]
ItemList1001[4].Consume=[500]


ItemList1002=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList1002[0].Base=4420
ItemList1002[0].Type=[ITEM_TRADE_BIJOU]
ItemList1002[0].Consume=[100]
ItemList1002[1].Base=4421
ItemList1002[1].Type=[ITEM_TRADE_BIJOU]
ItemList1002[1].Consume=[200]
ItemList1002[2].Base=4422
ItemList1002[2].Type=[ITEM_TRADE_BIJOU]
ItemList1002[2].Consume=[300]
ItemList1002[3].Base=4306
ItemList1002[3].Type=[ITEM_TRADE_BIJOU]
ItemList1002[3].Consume=[500]
ItemList1002[4].Base=4307
ItemList1002[4].Type=[ITEM_TRADE_BIJOU]
ItemList1002[4].Consume=[500]


ItemList1003=[ItemData(),ItemData()]
ItemList1003[0].Base=4010
ItemList1003[0].Type=[ITEM_TRADE_BIJOU]
ItemList1003[0].Consume=[100]
ItemList1003[1].Base=4040
ItemList1003[1].Type=[ITEM_TRADE_BIJOU]
ItemList1003[1].Consume=[200]


ItemList1004=[ItemData(),ItemData(),ItemData(),ItemData(),ItemData()]
ItemList1004[0].Base=4202
ItemList1004[0].Type=[ITEM_TRADE_BIJOU]
ItemList1004[0].Consume=[100]
ItemList1004[1].Base=4212
ItemList1004[1].Type=[ITEM_TRADE_BIJOU]
ItemList1004[1].Consume=[200]
ItemList1004[2].Base=4222
ItemList1004[2].Type=[ITEM_TRADE_BIJOU]
ItemList1004[2].Consume=[300]
ItemList1004[3].Base=4231
ItemList1004[3].Type=[ITEM_TRADE_BIJOU]
ItemList1004[3].Consume=[400]
ItemList1004[4].Base=4232
ItemList1004[4].Type=[ITEM_TRADE_BIJOU]
ItemList1004[4].Consume=[500]



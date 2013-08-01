<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.4">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="encoder">
<packages>
<package name="TQFP44-SOT376-1">
<wire x1="-4.91" y1="-4.91" x2="4.91" y2="-4.91" width="0.2032" layer="51"/>
<wire x1="4.91" y1="-4.91" x2="4.91" y2="4.91" width="0.2032" layer="51"/>
<wire x1="4.91" y1="4.91" x2="-4.91" y2="4.91" width="0.2032" layer="51"/>
<wire x1="-4.91" y1="4.91" x2="-4.91" y2="-4.91" width="0.2032" layer="51"/>
<wire x1="-4.72" y1="4.71" x2="4.71" y2="4.71" width="0.2032" layer="21"/>
<wire x1="4.71" y1="4.71" x2="4.71" y2="-4.71" width="0.2032" layer="21"/>
<wire x1="4.71" y1="-4.71" x2="-4.72" y2="-4.71" width="0.2032" layer="21"/>
<wire x1="-4.72" y1="-4.71" x2="-4.72" y2="4.71" width="0.2032" layer="21"/>
<circle x="-3.7501" y="-3.7501" radius="0.5002" width="0.254" layer="21"/>
<smd name="1" x="-4" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="2" x="-3.2" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="3" x="-2.4" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="4" x="-1.6" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="5" x="-0.8" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="6" x="0" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="7" x="0.8" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="8" x="1.6" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="9" x="2.4" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="10" x="3.2" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="11" x="4" y="-6" dx="0.5" dy="1.8" layer="1"/>
<smd name="12" x="6" y="-4" dx="1.8" dy="0.5" layer="1"/>
<smd name="13" x="6" y="-3.2" dx="1.8" dy="0.5" layer="1"/>
<smd name="14" x="6" y="-2.4" dx="1.8" dy="0.5" layer="1"/>
<smd name="15" x="6" y="-1.6" dx="1.8" dy="0.5" layer="1"/>
<smd name="16" x="6" y="-0.8" dx="1.8" dy="0.5" layer="1"/>
<smd name="17" x="6" y="0" dx="1.8" dy="0.5" layer="1"/>
<smd name="18" x="6" y="0.8" dx="1.8" dy="0.5" layer="1"/>
<smd name="19" x="6" y="1.6" dx="1.8" dy="0.5" layer="1"/>
<smd name="20" x="6" y="2.4" dx="1.8" dy="0.5" layer="1"/>
<smd name="21" x="6" y="3.2" dx="1.8" dy="0.5" layer="1"/>
<smd name="22" x="6" y="4" dx="1.8" dy="0.5" layer="1"/>
<smd name="23" x="4" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="24" x="3.2" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="25" x="2.4" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="26" x="1.6" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="27" x="0.8" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="28" x="0" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="29" x="-0.8" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="30" x="-1.6" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="31" x="-2.4" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="32" x="-3.2" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="33" x="-4" y="6" dx="0.5" dy="1.8" layer="1"/>
<smd name="34" x="-6" y="4" dx="1.8" dy="0.5" layer="1"/>
<smd name="35" x="-6" y="3.2" dx="1.8" dy="0.5" layer="1"/>
<smd name="36" x="-6" y="2.4" dx="1.8" dy="0.5" layer="1"/>
<smd name="37" x="-6" y="1.6" dx="1.8" dy="0.5" layer="1"/>
<smd name="38" x="-6" y="0.8" dx="1.8" dy="0.5" layer="1"/>
<smd name="39" x="-6" y="0" dx="1.8" dy="0.5" layer="1"/>
<smd name="40" x="-6" y="-0.8" dx="1.8" dy="0.5" layer="1"/>
<smd name="41" x="-6" y="-1.6" dx="1.8" dy="0.5" layer="1"/>
<smd name="42" x="-6" y="-2.4" dx="1.8" dy="0.5" layer="1"/>
<smd name="43" x="-6" y="-3.2" dx="1.8" dy="0.5" layer="1"/>
<smd name="44" x="-6" y="-4" dx="1.8" dy="0.5" layer="1"/>
<text x="-3.81" y="-2.175" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.81" y="1.905" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-4.22" y1="-6.7201" x2="-3.78" y2="-4.95" layer="51"/>
<rectangle x1="-3.4201" y1="-6.7201" x2="-2.9799" y2="-4.95" layer="51"/>
<rectangle x1="-2.62" y1="-6.7201" x2="-2.1801" y2="-4.95" layer="51"/>
<rectangle x1="-1.8199" y1="-6.7201" x2="-1.38" y2="-4.95" layer="51"/>
<rectangle x1="-1.0201" y1="-6.7201" x2="-0.5799" y2="-4.95" layer="51"/>
<rectangle x1="-0.22" y1="-6.7201" x2="0.22" y2="-4.95" layer="51"/>
<rectangle x1="0.5799" y1="-6.7201" x2="1.0201" y2="-4.95" layer="51"/>
<rectangle x1="1.38" y1="-6.7201" x2="1.8199" y2="-4.95" layer="51"/>
<rectangle x1="2.1801" y1="-6.7201" x2="2.62" y2="-4.95" layer="51"/>
<rectangle x1="2.9799" y1="-6.7201" x2="3.4201" y2="-4.95" layer="51"/>
<rectangle x1="3.78" y1="-6.7201" x2="4.22" y2="-4.95" layer="51"/>
<rectangle x1="4.95" y1="-4.22" x2="6.7201" y2="-3.78" layer="51"/>
<rectangle x1="4.95" y1="-3.4201" x2="6.7201" y2="-2.9799" layer="51"/>
<rectangle x1="4.95" y1="-2.62" x2="6.7201" y2="-2.1801" layer="51"/>
<rectangle x1="4.95" y1="-1.8199" x2="6.7201" y2="-1.38" layer="51"/>
<rectangle x1="4.95" y1="-1.0201" x2="6.7201" y2="-0.5799" layer="51"/>
<rectangle x1="4.95" y1="-0.22" x2="6.7201" y2="0.22" layer="51"/>
<rectangle x1="4.95" y1="0.5799" x2="6.7201" y2="1.0201" layer="51"/>
<rectangle x1="4.95" y1="1.38" x2="6.7201" y2="1.8199" layer="51"/>
<rectangle x1="4.95" y1="2.1801" x2="6.7201" y2="2.62" layer="51"/>
<rectangle x1="4.95" y1="2.9799" x2="6.7201" y2="3.4201" layer="51"/>
<rectangle x1="4.95" y1="3.78" x2="6.7201" y2="4.22" layer="51"/>
<rectangle x1="3.78" y1="4.95" x2="4.22" y2="6.7201" layer="51"/>
<rectangle x1="2.9799" y1="4.95" x2="3.4201" y2="6.7201" layer="51"/>
<rectangle x1="2.1801" y1="4.95" x2="2.62" y2="6.7201" layer="51"/>
<rectangle x1="1.38" y1="4.95" x2="1.8199" y2="6.7201" layer="51"/>
<rectangle x1="0.5799" y1="4.95" x2="1.0201" y2="6.7201" layer="51"/>
<rectangle x1="-0.22" y1="4.95" x2="0.22" y2="6.7201" layer="51"/>
<rectangle x1="-1.0201" y1="4.95" x2="-0.5799" y2="6.7201" layer="51"/>
<rectangle x1="-1.8199" y1="4.95" x2="-1.38" y2="6.7201" layer="51"/>
<rectangle x1="-2.62" y1="4.95" x2="-2.1801" y2="6.7201" layer="51"/>
<rectangle x1="-3.4201" y1="4.95" x2="-2.9799" y2="6.7201" layer="51"/>
<rectangle x1="-4.22" y1="4.95" x2="-3.78" y2="6.7201" layer="51"/>
<rectangle x1="-6.7201" y1="3.78" x2="-4.95" y2="4.22" layer="51"/>
<rectangle x1="-6.7201" y1="2.9799" x2="-4.95" y2="3.4201" layer="51"/>
<rectangle x1="-6.7201" y1="2.1801" x2="-4.95" y2="2.62" layer="51"/>
<rectangle x1="-6.7201" y1="1.38" x2="-4.95" y2="1.8199" layer="51"/>
<rectangle x1="-6.7201" y1="0.5799" x2="-4.95" y2="1.0201" layer="51"/>
<rectangle x1="-6.7201" y1="-0.22" x2="-4.95" y2="0.22" layer="51"/>
<rectangle x1="-6.7201" y1="-1.0201" x2="-4.95" y2="-0.5799" layer="51"/>
<rectangle x1="-6.7201" y1="-1.8199" x2="-4.95" y2="-1.38" layer="51"/>
<rectangle x1="-6.7201" y1="-2.62" x2="-4.95" y2="-2.1801" layer="51"/>
<rectangle x1="-6.7201" y1="-3.4201" x2="-4.95" y2="-2.9799" layer="51"/>
<rectangle x1="-6.7201" y1="-4.22" x2="-4.95" y2="-3.78" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="AM512B">
<wire x1="15.24" y1="-22.86" x2="-15.24" y2="-22.86" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-15.24" x2="-22.86" y2="15.24" width="0.254" layer="94"/>
<wire x1="-15.24" y1="22.86" x2="15.24" y2="22.86" width="0.254" layer="94"/>
<pin name="PROG" x="-12.7" y="-27.94" length="middle" direction="in" rot="R90"/>
<pin name="PRG" x="-10.16" y="-27.94" length="middle" direction="in" rot="R90"/>
<pin name="ERROR" x="-7.62" y="-27.94" length="middle" direction="out" rot="R90"/>
<pin name="COS" x="-5.08" y="-27.94" length="middle" direction="out" rot="R90"/>
<pin name="SIN" x="-2.54" y="-27.94" length="middle" direction="out" rot="R90"/>
<pin name="NC1" x="0" y="-27.94" length="middle" direction="nc" rot="R90"/>
<pin name="NC2" x="2.54" y="-27.94" length="middle" direction="nc" rot="R90"/>
<pin name="D8" x="5.08" y="-27.94" length="middle" direction="out" rot="R90"/>
<pin name="D7/DATA" x="7.62" y="-27.94" length="middle" direction="out" rot="R90"/>
<pin name="D6/VOUT" x="10.16" y="-27.94" length="middle" direction="out" rot="R90"/>
<pin name="D5" x="12.7" y="-27.94" length="middle" direction="out" rot="R90"/>
<pin name="BP1" x="27.94" y="-12.7" length="middle" direction="pwr" rot="R180"/>
<pin name="VSS1" x="27.94" y="-10.16" length="middle" direction="pwr" rot="R180"/>
<pin name="D4" x="27.94" y="-7.62" length="middle" direction="out" rot="R180"/>
<pin name="D3/A" x="27.94" y="-5.08" length="middle" direction="out" rot="R180"/>
<pin name="D2/RI" x="27.94" y="-2.54" length="middle" direction="out" rot="R180"/>
<pin name="VDD1" x="27.94" y="0" length="middle" direction="pwr" rot="R180"/>
<pin name="D1/B" x="27.94" y="2.54" length="middle" direction="out" rot="R180"/>
<pin name="D0" x="27.94" y="5.08" length="middle" direction="out" rot="R180"/>
<pin name="CS" x="27.94" y="7.62" length="middle" direction="in" rot="R180"/>
<pin name="CLOCK" x="27.94" y="10.16" length="middle" direction="in" function="clk" rot="R180"/>
<pin name="BP2" x="27.94" y="12.7" length="middle" direction="pwr" rot="R180"/>
<pin name="VSS2" x="12.7" y="27.94" length="middle" direction="pwr" rot="R270"/>
<pin name="REFN" x="10.16" y="27.94" length="middle" direction="in" rot="R270"/>
<pin name="VDD2" x="7.62" y="27.94" length="middle" direction="pwr" rot="R270"/>
<pin name="VSS3" x="5.08" y="27.94" length="middle" direction="pwr" rot="R270"/>
<pin name="DL" x="2.54" y="27.94" length="middle" direction="in" rot="R270"/>
<pin name="NC3" x="0" y="27.94" length="middle" direction="nc" rot="R270"/>
<pin name="VSS4" x="-2.54" y="27.94" length="middle" direction="pwr" rot="R270"/>
<pin name="VSS5" x="-5.08" y="27.94" length="middle" direction="pwr" rot="R270"/>
<pin name="VSS6" x="-7.62" y="27.94" length="middle" direction="pwr" rot="R270"/>
<pin name="VDD3" x="-10.16" y="27.94" length="middle" direction="pwr" rot="R270"/>
<pin name="VDD4" x="-12.7" y="27.94" length="middle" direction="pwr" rot="R270"/>
<pin name="BP3" x="-27.94" y="12.7" length="middle" direction="pwr"/>
<pin name="REFP" x="-27.94" y="10.16" length="middle" direction="in"/>
<pin name="AGND" x="-27.94" y="7.62" length="middle" direction="pwr"/>
<pin name="AGNDI" x="-27.94" y="5.08" length="middle" direction="pwr"/>
<pin name="LHAL" x="-27.94" y="2.54" length="middle" direction="in"/>
<pin name="NC4" x="-27.94" y="0" length="middle" direction="nc"/>
<pin name="LBOH" x="-27.94" y="-2.54" length="middle" direction="in"/>
<pin name="R25" x="-27.94" y="-5.08" length="middle" direction="in"/>
<pin name="PS" x="-27.94" y="-7.62" length="middle" direction="out"/>
<pin name="VSS7" x="-27.94" y="-10.16" length="middle" direction="pwr"/>
<pin name="BP4" x="-27.94" y="-12.7" length="middle" direction="pwr"/>
<wire x1="22.86" y1="15.24" x2="22.86" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-15.24" x2="-15.24" y2="-22.86" width="0.254" layer="94"/>
<wire x1="15.24" y1="-22.86" x2="22.86" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-15.24" y1="22.86" x2="-22.86" y2="15.24" width="0.254" layer="94"/>
<wire x1="15.24" y1="22.86" x2="22.86" y2="15.24" width="0.254" layer="94"/>
<circle x="-12.7" y="-12.7" radius="1.27" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="AM512B" prefix="IC">
<gates>
<gate name="G$1" symbol="AM512B" x="0" y="0"/>
</gates>
<devices>
<device name="LQFP44" package="TQFP44-SOT376-1">
<connects>
<connect gate="G$1" pin="AGND" pad="36"/>
<connect gate="G$1" pin="AGNDI" pad="37"/>
<connect gate="G$1" pin="BP1" pad="12"/>
<connect gate="G$1" pin="BP2" pad="22"/>
<connect gate="G$1" pin="BP3" pad="34"/>
<connect gate="G$1" pin="BP4" pad="44"/>
<connect gate="G$1" pin="CLOCK" pad="21"/>
<connect gate="G$1" pin="COS" pad="4"/>
<connect gate="G$1" pin="CS" pad="20"/>
<connect gate="G$1" pin="D0" pad="19"/>
<connect gate="G$1" pin="D1/B" pad="18"/>
<connect gate="G$1" pin="D2/RI" pad="16"/>
<connect gate="G$1" pin="D3/A" pad="15"/>
<connect gate="G$1" pin="D4" pad="14"/>
<connect gate="G$1" pin="D5" pad="11"/>
<connect gate="G$1" pin="D6/VOUT" pad="10"/>
<connect gate="G$1" pin="D7/DATA" pad="9"/>
<connect gate="G$1" pin="D8" pad="8"/>
<connect gate="G$1" pin="DL" pad="27"/>
<connect gate="G$1" pin="ERROR" pad="3"/>
<connect gate="G$1" pin="LBOH" pad="40"/>
<connect gate="G$1" pin="LHAL" pad="38"/>
<connect gate="G$1" pin="NC1" pad="6"/>
<connect gate="G$1" pin="NC2" pad="7"/>
<connect gate="G$1" pin="NC3" pad="28"/>
<connect gate="G$1" pin="NC4" pad="39"/>
<connect gate="G$1" pin="PRG" pad="2"/>
<connect gate="G$1" pin="PROG" pad="1"/>
<connect gate="G$1" pin="PS" pad="42"/>
<connect gate="G$1" pin="R25" pad="41"/>
<connect gate="G$1" pin="REFN" pad="24"/>
<connect gate="G$1" pin="REFP" pad="35"/>
<connect gate="G$1" pin="SIN" pad="5"/>
<connect gate="G$1" pin="VDD1" pad="17"/>
<connect gate="G$1" pin="VDD2" pad="25"/>
<connect gate="G$1" pin="VDD3" pad="32"/>
<connect gate="G$1" pin="VDD4" pad="33"/>
<connect gate="G$1" pin="VSS1" pad="13"/>
<connect gate="G$1" pin="VSS2" pad="23"/>
<connect gate="G$1" pin="VSS3" pad="26"/>
<connect gate="G$1" pin="VSS4" pad="29"/>
<connect gate="G$1" pin="VSS5" pad="30"/>
<connect gate="G$1" pin="VSS6" pad="31"/>
<connect gate="G$1" pin="VSS7" pad="43"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="frames">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="A4L-LOC">
<wire x1="256.54" y1="3.81" x2="256.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="256.54" y1="8.89" x2="256.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="256.54" y1="13.97" x2="256.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="256.54" y1="19.05" x2="256.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="161.29" y1="3.81" x2="161.29" y2="24.13" width="0.1016" layer="94"/>
<wire x1="161.29" y1="24.13" x2="215.265" y2="24.13" width="0.1016" layer="94"/>
<wire x1="215.265" y1="24.13" x2="256.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="246.38" y1="3.81" x2="246.38" y2="8.89" width="0.1016" layer="94"/>
<wire x1="246.38" y1="8.89" x2="256.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="246.38" y1="8.89" x2="215.265" y2="8.89" width="0.1016" layer="94"/>
<wire x1="215.265" y1="8.89" x2="215.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="215.265" y1="8.89" x2="215.265" y2="13.97" width="0.1016" layer="94"/>
<wire x1="215.265" y1="13.97" x2="256.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="215.265" y1="13.97" x2="215.265" y2="19.05" width="0.1016" layer="94"/>
<wire x1="215.265" y1="19.05" x2="256.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="215.265" y1="19.05" x2="215.265" y2="24.13" width="0.1016" layer="94"/>
<text x="217.17" y="15.24" size="2.54" layer="94" font="vector">&gt;DRAWING_NAME</text>
<text x="217.17" y="10.16" size="2.286" layer="94" font="vector">&gt;LAST_DATE_TIME</text>
<text x="230.505" y="5.08" size="2.54" layer="94" font="vector">&gt;SHEET</text>
<text x="216.916" y="4.953" size="2.54" layer="94" font="vector">Sheet:</text>
<frame x1="0" y1="0" x2="260.35" y2="179.07" columns="6" rows="4" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="A4L-LOC" prefix="FRAME" uservalue="yes">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A4, landscape with location and doc. field</description>
<gates>
<gate name="G$1" symbol="A4L-LOC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="IC1" library="encoder" deviceset="AM512B" device="LQFP44"/>
<part name="FRAME1" library="frames" deviceset="A4L-LOC" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="IC1" gate="G$1" x="127" y="99.06"/>
<instance part="FRAME1" gate="G$1" x="0" y="0"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>

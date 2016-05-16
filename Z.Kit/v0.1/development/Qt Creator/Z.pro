H = ../../API/C/Z
HPP = ../../API/C++/Z

INCLUDEPATH += \
	$$H \
	$$HPP \

HEADERS += \
	"$$H/ABIs/generic/allocation.h" \
	"$$H/ABIs/generic/cipher.h" \
	"$$H/ABIs/generic/data codec.h" \
	"$$H/ABIs/generic/emulation.h" \
	"$$H/ABIs/generic/hash function.h" \
	"$$H/ABIs/generic/module.h" \
	"$$H/ABIs/generic/wave codec.h" \
	"$$H/constants/alignment.h" \
	"$$H/constants/base.h" \
	"$$H/constants/color.h" \
	"$$H/constants/map.h" \
	"$$H/constants/music.h" \
	"$$H/constants/numbers.h" \
	"$$H/constants/science/chemical elements.h" \
	"$$H/constants/units.h" \
	"$$H/formats/archive/7z.h" \
	"$$H/formats/archive/7zX.h" \
	"$$H/formats/archive/ACE.h" \
	"$$H/formats/archive/AFA.h" \
	"$$H/formats/archive/ALZip.h" \
	"$$H/formats/archive/ARC.h" \
	"$$H/formats/archive/ARJ.h" \
	"$$H/formats/archive/Apple Disk Image.h" \
	"$$H/formats/archive/B1.h" \
	"$$H/formats/archive/Cabinet.h" \
	"$$H/formats/archive/Compact File Set.h" \
	"$$H/formats/archive/Compact Pro.h" \
	"$$H/formats/archive/DGCA.h" \
	"$$H/formats/archive/Disk Archiver.h" \
	"$$H/formats/archive/DiskDoubler.h" \
	"$$H/formats/archive/GCA.h" \
	"$$H/formats/archive/KGB.h" \
	"$$H/formats/archive/KiriKiri.h" \
	"$$H/formats/archive/LHA.h" \
	"$$H/formats/archive/LZX.h" \
	"$$H/formats/archive/PAK.h" \
	"$$H/formats/archive/PIM.h" \
	"$$H/formats/archive/PackIt.h" \
	"$$H/formats/archive/PartImage.h" \
	"$$H/formats/archive/PeaZip.h" \
	"$$H/formats/archive/PerfectCompress.h" \
	"$$H/formats/archive/Quadruple D.h" \
	"$$H/formats/archive/RAR.h" \
	"$$H/formats/archive/RK.h" \
	"$$H/formats/archive/SQX.h" \
	"$$H/formats/archive/Scifer.h" \
	"$$H/formats/archive/Self Dissolving ARChive.h" \
	"$$H/formats/archive/StuffIt X.h" \
	"$$H/formats/archive/StuffIt.h" \
	"$$H/formats/archive/TAR.h" \
	"$$H/formats/archive/UHarc.h" \
	"$$H/formats/archive/UltraCompressor II.h" \
	"$$H/formats/archive/Unix Archiver.h" \
	"$$H/formats/archive/Windows Image.h" \
	"$$H/formats/archive/XAR.h" \
	"$$H/formats/archive/YZ1.h" \
	"$$H/formats/archive/ZIP.h" \
	"$$H/formats/archive/ZPAQ.h" \
	"$$H/formats/archive/Zzip.h" \
	"$$H/formats/archive/cpio.h" \
	"$$H/formats/archive/zoo.h" \
	"$$H/formats/audio/Impulse Tracker.h" \
	"$$H/formats/audio/MO3.h" \
	"$$H/formats/audio/MOD.h" \
	"$$H/formats/audio/S3M.h" \
	"$$H/formats/audio/STM.h" \
	"$$H/formats/audio/XM.h" \
	"$$H/formats/character set/ASCII.h" \
	"$$H/formats/character set/Big5.h" \
	"$$H/formats/character set/DOS CP437.h" \
	"$$H/formats/character set/DOS CP737.h" \
	"$$H/formats/character set/DOS CP775.h" \
	"$$H/formats/character set/DOS CP850.h" \
	"$$H/formats/character set/DOS CP852.h" \
	"$$H/formats/character set/DOS CP855.h" \
	"$$H/formats/character set/DOS CP857.h" \
	"$$H/formats/character set/DOS CP858.h" \
	"$$H/formats/character set/DOS CP860.h" \
	"$$H/formats/character set/DOS CP861.h" \
	"$$H/formats/character set/DOS CP862.h" \
	"$$H/formats/character set/DOS CP863.h" \
	"$$H/formats/character set/DOS CP864.h" \
	"$$H/formats/character set/DOS CP865.h" \
	"$$H/formats/character set/DOS CP866.h" \
	"$$H/formats/character set/DOS CP869.h" \
	"$$H/formats/character set/DOS CP872.h" \
	"$$H/formats/character set/DOS CP874.h" \
	"$$H/formats/character set/EBCDIC CP037.h" \
	"$$H/formats/character set/EBCDIC CP1047.h" \
	"$$H/formats/character set/EBCDIC CP930.h" \
	"$$H/formats/character set/EUC-CN.h" \
	"$$H/formats/character set/EUC-JP.h" \
	"$$H/formats/character set/EUC-KR.h" \
	"$$H/formats/character set/EUC-TW.h" \
	"$$H/formats/character set/GB 18030.h" \
	"$$H/formats/character set/GB 2312.h" \
	"$$H/formats/character set/GBK.h" \
	"$$H/formats/character set/HKSCS.h" \
	"$$H/formats/character set/ISCII.h" \
	"$$H/formats/character set/ISO 8859-1.h" \
	"$$H/formats/character set/ISO 8859-10.h" \
	"$$H/formats/character set/ISO 8859-11.h" \
	"$$H/formats/character set/ISO 8859-13.h" \
	"$$H/formats/character set/ISO 8859-14.h" \
	"$$H/formats/character set/ISO 8859-15.h" \
	"$$H/formats/character set/ISO 8859-16.h" \
	"$$H/formats/character set/ISO 8859-2.h" \
	"$$H/formats/character set/ISO 8859-3.h" \
	"$$H/formats/character set/ISO 8859-4.h" \
	"$$H/formats/character set/ISO 8859-5.h" \
	"$$H/formats/character set/ISO 8859-6.h" \
	"$$H/formats/character set/ISO 8859-7.h" \
	"$$H/formats/character set/ISO 8859-8.h" \
	"$$H/formats/character set/ISO 8859-9.h" \
	"$$H/formats/character set/KOI7.h" \
	"$$H/formats/character set/KOI8-R.h" \
	"$$H/formats/character set/KOI8-U.h" \
	"$$H/formats/character set/KS X 1001.h" \
	"$$H/formats/character set/MIK.h" \
	"$$H/formats/character set/Mac OS Roman.h" \
	"$$H/formats/character set/Shift JIS.h" \
	"$$H/formats/character set/TSCII.h" \
	"$$H/formats/character set/Unicode.h" \
	"$$H/formats/character set/VISCII.h" \
	"$$H/formats/character set/Windows 1250.h" \
	"$$H/formats/character set/Windows 1251.h" \
	"$$H/formats/character set/Windows 1252.h" \
	"$$H/formats/character set/Windows 1253.h" \
	"$$H/formats/character set/Windows 1254.h" \
	"$$H/formats/character set/Windows 1255.h" \
	"$$H/formats/character set/Windows 1256.h" \
	"$$H/formats/character set/Windows 1257.h" \
	"$$H/formats/character set/Windows 1258.h" \
	"$$H/formats/color/A 8.h" \
	"$$H/formats/color/ARGB 1-5-5-5.h" \
	"$$H/formats/color/ARGB 4-4-4-4.h" \
	"$$H/formats/color/ARGB 8-8-8-8.h" \
	"$$H/formats/color/I 8.h" \
	"$$H/formats/color/RGB 5-6-5.h" \
	"$$H/formats/color/RGBA 4-4-4-4.h" \
	"$$H/formats/color/RGBA 5-5-5-1.h" \
	"$$H/formats/color/RGBA 8-8-8-8.h" \
	"$$H/formats/data model/ILP32.h" \
	"$$H/formats/data model/ILP64.h" \
	"$$H/formats/data model/LLP64.h" \
	"$$H/formats/data model/LP32.h" \
	"$$H/formats/data model/LP64.h" \
	"$$H/formats/data model/SILP64.h" \
	"$$H/formats/file system/ADFS.h" \
	"$$H/formats/file system/BFS.h" \
	"$$H/formats/file system/BeFS.h" \
	"$$H/formats/file system/Btrfs.h" \
	"$$H/formats/file system/CramFS.h" \
	"$$H/formats/file system/EFS.h" \
	"$$H/formats/file system/Ext2.h" \
	"$$H/formats/file system/Ext3.h" \
	"$$H/formats/file system/Ext4.h" \
	"$$H/formats/file system/FAT.h" \
	"$$H/formats/file system/FAT12.h" \
	"$$H/formats/file system/FAT16.h" \
	"$$H/formats/file system/FAT32.h" \
	"$$H/formats/file system/FFS.h" \
	"$$H/formats/file system/HFS+.h" \
	"$$H/formats/file system/HFS.h" \
	"$$H/formats/file system/HPFS.h" \
	"$$H/formats/file system/ISO 9660.h" \
	"$$H/formats/file system/JFS.h" \
	"$$H/formats/file system/LogFS.h" \
	"$$H/formats/file system/Minix FS.h" \
	"$$H/formats/file system/NILFS2.h" \
	"$$H/formats/file system/NTFS.h" \
	"$$H/formats/file system/OFS.h" \
	"$$H/formats/file system/QNX v4 FS.h" \
	"$$H/formats/file system/QNX v6 FS.h" \
	"$$H/formats/file system/ROM FS.h" \
	"$$H/formats/file system/ReiserFS.h" \
	"$$H/formats/file system/SonicBlue Optimized MPEG FS.h" \
	"$$H/formats/file system/SquashFS.h" \
	"$$H/formats/file system/System V FS.h" \
	"$$H/formats/file system/UDF.h" \
	"$$H/formats/file system/UFS.h" \
	"$$H/formats/file system/VxFS.h" \
	"$$H/formats/file system/XFS.h" \
	"$$H/formats/floating point/IEEE 754.h" \
	"$$H/formats/floating point/Intel.h" \
	"$$H/formats/image/BMP.h" \
	"$$H/formats/image/GIF.h" \
	"$$H/formats/image/ICNS.h" \
	"$$H/formats/image/JPEG.h" \
	"$$H/formats/image/PCX.h" \
	"$$H/formats/image/PNG.h" \
	"$$H/formats/image/PSD.h" \
	"$$H/formats/image/TGA.h" \
	"$$H/formats/image/TIFF.h" \
	"$$H/formats/keymap/Apple.h" \
	"$$H/formats/multimedia container/ASF.h" \
	"$$H/formats/multimedia container/AU.h" \
	"$$H/formats/multimedia container/AVI.h" \
	"$$H/formats/multimedia container/Creative Voice.h" \
	"$$H/formats/multimedia container/MP4.h" \
	"$$H/formats/multimedia container/Matroska.h" \
	"$$H/formats/multimedia container/Microsoft Wave.h" \
	"$$H/formats/multimedia container/RIFF.h" \
	"$$H/formats/program/CMD.h" \
	"$$H/formats/program/COFF.h" \
	"$$H/formats/program/ECOFF.h" \
	"$$H/formats/program/ELF.h" \
	"$$H/formats/program/Hunk.h" \
	"$$H/formats/program/LX.h" \
	"$$H/formats/program/MZ.h" \
	"$$H/formats/program/Mach-O.h" \
	"$$H/formats/program/NE.h" \
	"$$H/formats/program/OS-360.h" \
	"$$H/formats/program/PE.h" \
	"$$H/formats/program/PEF.h" \
	"$$H/formats/program/RDOFF.h" \
	"$$H/formats/program/SOM.h" \
	"$$H/formats/program/XCOFF.h" \
	"$$H/formats/program/a.out.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/89C.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/ACH.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/FRZ.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/PLUSD.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/PRG.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SEM.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SIT.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SNA.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SNP.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SNX.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SP.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/STL.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SZX.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/Z80.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/ZLS.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/ZX.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/ZX82.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/ZXS.h" \
	"$$H/formats/storage medium image/Disk Card/FDS.h" \
	"$$H/formats/storage medium image/NES Game Pak/UNIF.h" \
	"$$H/formats/storage medium image/NES Game Pak/iNES.h" \
	"$$H/formats/storage medium image/Nintendo 64 Game Pack/Doctor V64.h" \
	"$$H/formats/storage medium image/Nintendo 64 Game Pack/Mr. Backup Z64.h" \
	"$$H/formats/storage medium image/SNES Game Pak/Super Magicom.h" \
	"$$H/formats/storage medium image/ZX Microdrive/MDR.h" \
	"$$H/formats/storage medium image/audio/ITM.h" \
	"$$H/formats/storage medium image/audio/PZX.h" \
	"$$H/formats/storage medium image/audio/T64.h" \
	"$$H/formats/storage medium image/audio/TAP.h" \
	"$$H/formats/storage medium image/audio/TZX.h" \
	"$$H/formats/storage medium image/audio/Warajevo TAP.h" \
	"$$H/formats/storage medium image/floppy disk/ADF.h" \
	"$$H/formats/storage medium image/floppy disk/D64.h" \
	"$$H/formats/storage medium image/floppy disk/DSK.h" \
	"$$H/formats/storage medium image/floppy disk/FDI.h" \
	"$$H/formats/storage medium image/floppy disk/IPF.h" \
	"$$H/formats/storage medium image/floppy disk/TRD.h" \
	"$$H/formats/storage medium image/floppy disk/TeleDisk.h" \
	"$$H/formats/storage medium image/floppy disk/X64.h" \
	"$$H/formats/storage medium image/optical disc/CDRWIN.h" \
	"$$H/formats/storage medium image/optical disc/CloneCD.h" \
	"$$H/formats/storage medium image/optical disc/NRG.h" \
	"$$H/formats/wave/ADPCM.h" \
	"$$H/formats/wave/PCM.h" \
	"$$H/functions/assembly/x86/x86-32/CPU.h" \
	"$$H/functions/assembly/x86/x86-32/FPU.h" \
	"$$H/functions/assembly/x86/x86-32/value.h" \
	"$$H/functions/assembly/x86/x86-64/CPU.h" \
	"$$H/functions/assembly/x86/x86-64/FPU.h" \
	"$$H/functions/assembly/x86/x86-64/value.h" \
	"$$H/functions/base/Z2DValue.h" \
	"$$H/functions/base/Z3DValue.h" \
	"$$H/functions/base/ZRange.h" \
	"$$H/functions/base/all.h" \
	"$$H/functions/base/character.h" \
	"$$H/functions/base/constructors.h" \
	"$$H/functions/base/value.h" \
	"$$H/functions/buffering/ZRingBuffer.h" \
	"$$H/functions/buffering/ZTripleBuffer.h" \
	"$$H/functions/color/ZARGB1555.h" \
	"$$H/functions/color/ZARGB4444.h" \
	"$$H/functions/color/ZARGB8888.h" \
	"$$H/functions/color/ZRGB565.h" \
	"$$H/functions/color/ZRGBA4444.h" \
	"$$H/functions/color/ZRGBA5551.h" \
	"$$H/functions/color/ZRGBA8888.h" \
	"$$H/functions/color/conversion.h" \
	"$$H/functions/data/ZChainNode.h" \
	"$$H/functions/data/ZListNode.h" \
	"$$H/functions/data/ZTreeNode.h" \
	"$$H/functions/mathematics/geometry/euclidean/Z2DLine.h" \
	"$$H/functions/mathematics/geometry/euclidean/Z3DLine.h" \
	"$$H/functions/mathematics/geometry/euclidean/ZAABB.h" \
	"$$H/functions/mathematics/geometry/euclidean/ZAABR.h" \
	"$$H/functions/mathematics/geometry/euclidean/ZBox.h" \
	"$$H/functions/mathematics/geometry/euclidean/ZCircle.h" \
	"$$H/functions/mathematics/geometry/euclidean/ZRectangle.h" \
	"$$H/functions/mathematics/geometry/euclidean/ZSphere.h" \
	"$$H/functions/mathematics/geometry/euclidean/all.h" \
	"$$H/functions/mathematics/geometry/euclidean/constructors.h" \
	"$$H/functions/time/ZAttotime.h" \
	"$$H/functions/time/ZNanotime.h" \
	"$$H/functions/time/date.h" \
	"$$H/hardware/BUS/AGP.h" \
	"$$H/hardware/BUS/ISA.h" \
	"$$H/hardware/BUS/PCI Express.h" \
	"$$H/hardware/BUS/PCI-X.h" \
	"$$H/hardware/BUS/PCI.h" \
	"$$H/hardware/BUS/USB.h" \
	"$$H/hardware/BUS/VESA Local Bus.h" \
	"$$H/hardware/CPU/architecture/650x.h" \
	"$$H/hardware/CPU/architecture/AArch64.h" \
	"$$H/hardware/CPU/architecture/ARM.h" \
	"$$H/hardware/CPU/architecture/Blackfin.h" \
	"$$H/hardware/CPU/architecture/Convex.h" \
	"$$H/hardware/CPU/architecture/Epiphany.h" \
	"$$H/hardware/CPU/architecture/Itanium.h" \
	"$$H/hardware/CPU/architecture/M68K.h" \
	"$$H/hardware/CPU/architecture/MIPS.h" \
	"$$H/hardware/CPU/architecture/PA-RISC.h" \
	"$$H/hardware/CPU/architecture/PowerPC 32-bit.h" \
	"$$H/hardware/CPU/architecture/PowerPC 64-bit.h" \
	"$$H/hardware/CPU/architecture/Pyramid 9810.h" \
	"$$H/hardware/CPU/architecture/RS 6000.h" \
	"$$H/hardware/CPU/architecture/SPARC.h" \
	"$$H/hardware/CPU/architecture/SuperH.h" \
	"$$H/hardware/CPU/architecture/System 370.h" \
	"$$H/hardware/CPU/architecture/System 390.h" \
	"$$H/hardware/CPU/architecture/TMS320.h" \
	"$$H/hardware/CPU/architecture/Z80.h" \
	"$$H/hardware/CPU/architecture/i4004.h" \
	"$$H/hardware/CPU/architecture/i8008.h" \
	"$$H/hardware/CPU/architecture/x86-16.h" \
	"$$H/hardware/CPU/architecture/x86-32.h" \
	"$$H/hardware/CPU/architecture/x86-64.h" \
	"$$H/hardware/CPU/architecture/z Architecture.h" \
	"$$H/hardware/CPU/model/650x/MOS Technology/6502.h" \
	"$$H/hardware/CPU/model/650x/Ricoh/RP2A03.h" \
	"$$H/hardware/CPU/model/650x/Ricoh/RP2A07.h" \
	"$$H/hardware/CPU/model/68k/Motorola/MC68000.h" \
	"$$H/hardware/CPU/model/Z80/Zilog/Z8400.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80386/Am386DX DXL-25.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80386/Am386DX DXL-33.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80386/Am386DX DXL-40.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80386/Am386DX-33.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80386/Am386DX-40.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80386/Am386SX SXL-25.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80386/Am386SX SXL-33.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80386/Am386SX-20.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DE2-66V8TGC.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DE2-66V8THC.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX-25.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX-33.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX-40.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX2-50.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX2-66.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX2-66NV8T.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX2-66SV8B.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX2-66V16BGC.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX2-80 V8T.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX2-80.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX2-80NV8T.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-100.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-100NV8T.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-100SV16BGI.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-100SV8B.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-100V16BGC.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-120.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-120NV8T.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-120SV8B.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-75.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486DX4-90NV8T.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486SX-33.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486SX-40.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486SX2-50.h" \
	"$$H/hardware/CPU/model/x86/AMD/i80486/Am486SX2-66.h" \
	"$$H/hardware/GPU/3dfx Interactive/Spectre 1000.h" \
	"$$H/hardware/GPU/3dfx Interactive/Spectre 2000.h" \
	"$$H/hardware/GPU/3dfx Interactive/Spectre 3000.h" \
	"$$H/hardware/GPU/3dfx Interactive/Velocity 100.h" \
	"$$H/hardware/GPU/3dfx Interactive/Velocity 200.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo Banshee.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo Graphics.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo Rush.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo2.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo3 1000.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo3 2000.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo3 3000.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo3 3500 TV.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo4 4200.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo4 4500.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo4 4800.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo5 5000.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo5 5500.h" \
	"$$H/hardware/GPU/3dfx Interactive/Voodoo5 6000.h" \
	"$$H/hardware/PSG/General Instrument/AY-3-891x.h" \
	"$$H/hardware/PSG/Texas Instruments/SN76489.h" \
	"$$H/hardware/PSG/Yamaha/YM2610.h" \
	"$$H/hardware/TV/NTSC.h" \
	"$$H/hardware/TV/PAL.h" \
	"$$H/hardware/TV/SECAM.h" \
	"$$H/hardware/VDC/Ricoh/RP2C0x.h" \
	"$$H/hardware/device/ZX Spectrum/Beta 128 Disk Interface.h" \
	"$$H/hardware/device/ZX Spectrum/Beta Disk Interface.h" \
	"$$H/hardware/device/ZX Spectrum/DISCiPLE.h" \
	"$$H/hardware/device/ZX Spectrum/ZX Interface 1.h" \
	"$$H/hardware/device/ZX Spectrum/ZX Interface 2.h" \
	"$$H/hardware/device/multi-platform/HID/PowerMate.h" \
	"$$H/hardware/machine/model/computer/CPC/CPC 464 plus.h" \
	"$$H/hardware/machine/model/computer/CPC/CPC 464.h" \
	"$$H/hardware/machine/model/computer/CPC/CPC 472.h" \
	"$$H/hardware/machine/model/computer/CPC/CPC 6128 plus.h" \
	"$$H/hardware/machine/model/computer/CPC/CPC 6128.h" \
	"$$H/hardware/machine/model/computer/CPC/CPC 664.h" \
	"$$H/hardware/machine/model/computer/CPC/KC Kompact.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/Inves Spectrum +.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/Pentagon.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/Scorpion.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum + 128K.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +2.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +2A.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +3.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum.h" \
	"$$H/hardware/machine/model/console/Nintendo Entertainment System/Dendy.h" \
	"$$H/hardware/machine/model/console/Nintendo Entertainment System/HVC-001.h" \
	"$$H/hardware/machine/model/console/Nintendo Entertainment System/NES-001 (NTSC).h" \
	"$$H/hardware/machine/model/console/Nintendo Entertainment System/NES-001 (PAL).h" \
	"$$H/hardware/machine/platform/arcade/Atari System 1.h" \
	"$$H/hardware/machine/platform/arcade/Atari System 2.h" \
	"$$H/hardware/machine/platform/arcade/Atomiswave.h" \
	"$$H/hardware/machine/platform/arcade/Bemani System 573 Analog.h" \
	"$$H/hardware/machine/platform/arcade/CP System II.h" \
	"$$H/hardware/machine/platform/arcade/CP System III.h" \
	"$$H/hardware/machine/platform/arcade/CP System.h" \
	"$$H/hardware/machine/platform/arcade/DECO Cassette System.h" \
	"$$H/hardware/machine/platform/arcade/Hyper Neo-Geo 64.h" \
	"$$H/hardware/machine/platform/arcade/Konami GX.h" \
	"$$H/hardware/machine/platform/arcade/Konami GX400.h" \
	"$$H/hardware/machine/platform/arcade/Kyugo.h" \
	"$$H/hardware/machine/platform/arcade/Namco Galaxian.h" \
	"$$H/hardware/machine/platform/arcade/Namco NA-1.h" \
	"$$H/hardware/machine/platform/arcade/Namco NB-1.h" \
	"$$H/hardware/machine/platform/arcade/Namco ND-1.h" \
	"$$H/hardware/machine/platform/arcade/Namco Pac-Land.h" \
	"$$H/hardware/machine/platform/arcade/Namco Pac-Man.h" \
	"$$H/hardware/machine/platform/arcade/Namco Phozon.h" \
	"$$H/hardware/machine/platform/arcade/Namco Pole Position.h" \
	"$$H/hardware/machine/platform/arcade/Namco Super Pac-Man.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 1.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 10.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 11.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 12.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 2.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 21.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 22.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 23.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 246.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 357.h" \
	"$$H/hardware/machine/platform/arcade/Namco System 86.h" \
	"$$H/hardware/machine/platform/arcade/Neo-Geo MVS.h" \
	"$$H/hardware/machine/platform/arcade/Nu.h" \
	"$$H/hardware/machine/platform/arcade/PlayChoice-10.h" \
	"$$H/hardware/machine/platform/arcade/PolyGame Master.h" \
	"$$H/hardware/machine/platform/arcade/RingEdge 2.h" \
	"$$H/hardware/machine/platform/arcade/RingEdge.h" \
	"$$H/hardware/machine/platform/arcade/RingWide.h" \
	"$$H/hardware/machine/platform/arcade/ST-V.h" \
	"$$H/hardware/machine/platform/arcade/Sega Blockade.h" \
	"$$H/hardware/machine/platform/arcade/Sega Chihiro.h" \
	"$$H/hardware/machine/platform/arcade/Sega Europa-R.h" \
	"$$H/hardware/machine/platform/arcade/Sega G80.h" \
	"$$H/hardware/machine/platform/arcade/Sega Hikaru.h" \
	"$$H/hardware/machine/platform/arcade/Sega Lindbergh.h" \
	"$$H/hardware/machine/platform/arcade/Sega Mega-Play.h" \
	"$$H/hardware/machine/platform/arcade/Sega Mega-Tech.h" \
	"$$H/hardware/machine/platform/arcade/Sega Model 1.h" \
	"$$H/hardware/machine/platform/arcade/Sega Model 2.h" \
	"$$H/hardware/machine/platform/arcade/Sega Model 3.h" \
	"$$H/hardware/machine/platform/arcade/Sega NAOMI 2.h" \
	"$$H/hardware/machine/platform/arcade/Sega NAOMI.h" \
	"$$H/hardware/machine/platform/arcade/Sega OutRun.h" \
	"$$H/hardware/machine/platform/arcade/Sega Space Harrier.h" \
	"$$H/hardware/machine/platform/arcade/Sega System 1.h" \
	"$$H/hardware/machine/platform/arcade/Sega System 14.h" \
	"$$H/hardware/machine/platform/arcade/Sega System 16.h" \
	"$$H/hardware/machine/platform/arcade/Sega System 18.h" \
	"$$H/hardware/machine/platform/arcade/Sega System 24.h" \
	"$$H/hardware/machine/platform/arcade/Sega System 32.h" \
	"$$H/hardware/machine/platform/arcade/Sega System Multi 32.h" \
	"$$H/hardware/machine/platform/arcade/Sega VIC Dual.h" \
	"$$H/hardware/machine/platform/arcade/Sega X Board.h" \
	"$$H/hardware/machine/platform/arcade/Sega Y Board.h" \
	"$$H/hardware/machine/platform/arcade/Sega Z80.h" \
	"$$H/hardware/machine/platform/arcade/Sega Zaxxon.h" \
	"$$H/hardware/machine/platform/arcade/TIA-MC-1.h" \
	"$$H/hardware/machine/platform/arcade/Taito B System.h" \
	"$$H/hardware/machine/platform/arcade/Taito F3 System.h" \
	"$$H/hardware/machine/platform/arcade/Taito L System.h" \
	"$$H/hardware/machine/platform/arcade/Taito SJ System.h" \
	"$$H/hardware/machine/platform/arcade/Taito Type X Zero.h" \
	"$$H/hardware/machine/platform/arcade/Taito Type X+.h" \
	"$$H/hardware/machine/platform/arcade/Taito Type X.h" \
	"$$H/hardware/machine/platform/arcade/Taito Type X2.h" \
	"$$H/hardware/machine/platform/arcade/Taito X System.h" \
	"$$H/hardware/machine/platform/arcade/Taito Z System.h" \
	"$$H/hardware/machine/platform/arcade/Triforce.h" \
	"$$H/hardware/machine/platform/arcade/VCO Object.h" \
	"$$H/hardware/machine/platform/calculator/TI-73.h" \
	"$$H/hardware/machine/platform/calculator/TI-80.h" \
	"$$H/hardware/machine/platform/calculator/TI-82.h" \
	"$$H/hardware/machine/platform/calculator/TI-83.h" \
	"$$H/hardware/machine/platform/calculator/TI-84+.h" \
	"$$H/hardware/machine/platform/calculator/TI-85.h" \
	"$$H/hardware/machine/platform/calculator/TI-86.h" \
	"$$H/hardware/machine/platform/calculator/TI-89.h" \
	"$$H/hardware/machine/platform/calculator/TI-92.h" \
	"$$H/hardware/machine/platform/computer/Amiga.h" \
	"$$H/hardware/machine/platform/computer/Apple I.h" \
	"$$H/hardware/machine/platform/computer/BeBox.h" \
	"$$H/hardware/machine/platform/computer/CPC.h" \
	"$$H/hardware/machine/platform/computer/Commodore 128.h" \
	"$$H/hardware/machine/platform/computer/Commodore 16.h" \
	"$$H/hardware/machine/platform/computer/Commodore 64.h" \
	"$$H/hardware/machine/platform/computer/Jupiter ACE.h" \
	"$$H/hardware/machine/platform/computer/KIM-1.h" \
	"$$H/hardware/machine/platform/computer/Lisa.h" \
	"$$H/hardware/machine/platform/computer/MAX Machine.h" \
	"$$H/hardware/machine/platform/computer/MSX.h" \
	"$$H/hardware/machine/platform/computer/Macintosh.h" \
	"$$H/hardware/machine/platform/computer/MicroBee.h" \
	"$$H/hardware/machine/platform/computer/Microtan 65.h" \
	"$$H/hardware/machine/platform/computer/Oric-1.h" \
	"$$H/hardware/machine/platform/computer/PC Jr.h" \
	"$$H/hardware/machine/platform/computer/PC.h" \
	"$$H/hardware/machine/platform/computer/PET.h" \
	"$$H/hardware/machine/platform/computer/QL.h" \
	"$$H/hardware/machine/platform/computer/SAM Coupe.h" \
	"$$H/hardware/machine/platform/computer/ST.h" \
	"$$H/hardware/machine/platform/computer/VIC-20.h" \
	"$$H/hardware/machine/platform/computer/Z88.h" \
	"$$H/hardware/machine/platform/computer/ZX Spectrum.h" \
	"$$H/hardware/machine/platform/computer/ZX80.h" \
	"$$H/hardware/machine/platform/computer/ZX81.h" \
	"$$H/hardware/machine/platform/console/3DO Interactive Multiplayer.h" \
	"$$H/hardware/machine/platform/console/Adventure Vision.h" \
	"$$H/hardware/machine/platform/console/Amiga CD32.h" \
	"$$H/hardware/machine/platform/console/Arcadia 2001.h" \
	"$$H/hardware/machine/platform/console/Astrocade.h" \
	"$$H/hardware/machine/platform/console/Atari 2600.h" \
	"$$H/hardware/machine/platform/console/Atari 5200 SuperSystem.h" \
	"$$H/hardware/machine/platform/console/Atari 7800 ProSystem.h" \
	"$$H/hardware/machine/platform/console/Bridge Companion.h" \
	"$$H/hardware/machine/platform/console/CD-i.h" \
	"$$H/hardware/machine/platform/console/Channel F.h" \
	"$$H/hardware/machine/platform/console/ColecoVision.h" \
	"$$H/hardware/machine/platform/console/Dreamcast.h" \
	"$$H/hardware/machine/platform/console/GX4000.h" \
	"$$H/hardware/machine/platform/console/Game Boy Advance.h" \
	"$$H/hardware/machine/platform/console/Game Boy.h" \
	"$$H/hardware/machine/platform/console/Game Gear.h" \
	"$$H/hardware/machine/platform/console/Game Pocket Computer.h" \
	"$$H/hardware/machine/platform/console/GameCube.h" \
	"$$H/hardware/machine/platform/console/Intellivision.h" \
	"$$H/hardware/machine/platform/console/Jaguar.h" \
	"$$H/hardware/machine/platform/console/Loopy.h" \
	"$$H/hardware/machine/platform/console/Lynx.h" \
	"$$H/hardware/machine/platform/console/Master System.h" \
	"$$H/hardware/machine/platform/console/Mega Drive.h" \
	"$$H/hardware/machine/platform/console/Neo-Geo AES.h" \
	"$$H/hardware/machine/platform/console/Neo-Geo CD.h" \
	"$$H/hardware/machine/platform/console/Neo-Geo Pocket.h" \
	"$$H/hardware/machine/platform/console/Nintendo 64.h" \
	"$$H/hardware/machine/platform/console/Nintendo DS.h" \
	"$$H/hardware/machine/platform/console/Nintendo Entertainment System.h" \
	"$$H/hardware/machine/platform/console/Odyssey 2.h" \
	"$$H/hardware/machine/platform/console/Odyssey 200.h" \
	"$$H/hardware/machine/platform/console/Odyssey.h" \
	"$$H/hardware/machine/platform/console/PC-FX.h" \
	"$$H/hardware/machine/platform/console/PV-1000.h" \
	"$$H/hardware/machine/platform/console/PasoGo.h" \
	"$$H/hardware/machine/platform/console/PlayStation 2.h" \
	"$$H/hardware/machine/platform/console/PlayStation 3.h" \
	"$$H/hardware/machine/platform/console/PlayStation 4.h" \
	"$$H/hardware/machine/platform/console/PlayStation Portable.h" \
	"$$H/hardware/machine/platform/console/PlayStation Vita.h" \
	"$$H/hardware/machine/platform/console/PlayStation.h" \
	"$$H/hardware/machine/platform/console/Playdia.h" \
	"$$H/hardware/machine/platform/console/PocketStation.h" \
	"$$H/hardware/machine/platform/console/SG-1000.h" \
	"$$H/hardware/machine/platform/console/Sega Saturn.h" \
	"$$H/hardware/machine/platform/console/Studio II.h" \
	"$$H/hardware/machine/platform/console/Super Cassette Vision.h" \
	"$$H/hardware/machine/platform/console/Super Nintendo Entertainment System.h" \
	"$$H/hardware/machine/platform/console/TurboGrafx-16.h" \
	"$$H/hardware/machine/platform/console/VC 4000.h" \
	"$$H/hardware/machine/platform/console/Vectrex.h" \
	"$$H/hardware/machine/platform/console/Virtual Boy.h" \
	"$$H/hardware/machine/platform/console/Wii U.h" \
	"$$H/hardware/machine/platform/console/Wii.h" \
	"$$H/hardware/machine/platform/console/WonderSwan.h" \
	"$$H/hardware/storage medium/ROM cartridge/3DS Game Card.h" \
	"$$H/hardware/storage medium/ROM cartridge/Atari 2600 Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Atari 5200 Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Atari 7800 Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Atomiswave Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Commodore 16 Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Commodore 64 Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Game Boy Game Pak.h" \
	"$$H/hardware/storage medium/ROM cartridge/Game Card.h" \
	"$$H/hardware/storage medium/ROM cartridge/HuCARD.h" \
	"$$H/hardware/storage medium/ROM cartridge/Master System Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Mega Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Mega Drive Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/My Card EP.h" \
	"$$H/hardware/storage medium/ROM cartridge/My Card Mark III.h" \
	"$$H/hardware/storage medium/ROM cartridge/My Card.h" \
	"$$H/hardware/storage medium/ROM cartridge/NES Game Pak.h" \
	"$$H/hardware/storage medium/ROM cartridge/Neo-Geo AES Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Neo-Geo MVS Cartridge.h" \
	"$$H/hardware/storage medium/ROM cartridge/Nintendo 64 Game Pak.h" \
	"$$H/hardware/storage medium/ROM cartridge/SNES Game Pak.h" \
	"$$H/hardware/storage medium/ROM cartridge/ST-V Cartridge.h" \
	"$$H/hardware/storage medium/floppy disk/64DD.h" \
	"$$H/hardware/storage medium/floppy disk/DataDisk.h" \
	"$$H/hardware/storage medium/floppy disk/Disk Card.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 2-inch.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 3-inch DD.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 3-inch.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 3.5 SS.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 3.5-inch DD.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 3.5-inch ED.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 3.5-inch HD.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 5.25-inch DD.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 5.25-inch HD.h" \
	"$$H/hardware/storage medium/floppy disk/Floppy Disk 5.25-inch QD.h" \
	"$$H/hardware/storage medium/floppy disk/IBM 23FD.h" \
	"$$H/hardware/storage medium/floppy disk/IBM 33FD.h" \
	"$$H/hardware/storage medium/floppy disk/IBM 43FD.h" \
	"$$H/hardware/storage medium/floppy disk/IBM 53FD.h" \
	"$$H/hardware/storage medium/floppy disk/Memorex 651.h" \
	"$$H/hardware/storage medium/floppy disk/Quick Disk.h" \
	"$$H/hardware/storage medium/magnetic tape/Betamax.h" \
	"$$H/hardware/storage medium/magnetic tape/Compact Cassette.h" \
	"$$H/hardware/storage medium/magnetic tape/VHS.h" \
	"$$H/hardware/storage medium/magnetic tape/Video 2000.h" \
	"$$H/hardware/storage medium/optical disc/BD.h" \
	"$$H/hardware/storage medium/optical disc/CD.h" \
	"$$H/hardware/storage medium/optical disc/DVD.h" \
	"$$H/hardware/storage medium/optical disc/DataPlay.h" \
	"$$H/hardware/storage medium/optical disc/DualDisc.h" \
	"$$H/hardware/storage medium/optical disc/EVD.h" \
	"$$H/hardware/storage medium/optical disc/FMD.h" \
	"$$H/hardware/storage medium/optical disc/FVD.h" \
	"$$H/hardware/storage medium/optical disc/GD-ROM.h" \
	"$$H/hardware/storage medium/optical disc/GameCube Game Disc.h" \
	"$$H/hardware/storage medium/optical disc/HD DVD.h" \
	"$$H/hardware/storage medium/optical disc/HD VMD.h" \
	"$$H/hardware/storage medium/optical disc/HVD.h" \
	"$$H/hardware/storage medium/optical disc/LaserDisc.h" \
	"$$H/hardware/storage medium/optical disc/MODS-Disc.h" \
	"$$H/hardware/storage medium/optical disc/PCD.h" \
	"$$H/hardware/storage medium/optical disc/Super Audio CD.h" \
	"$$H/hardware/storage medium/optical disc/UDO.h" \
	"$$H/hardware/storage medium/optical disc/UMD.h" \
	"$$H/hardware/storage medium/optical disc/Wii Optical Disc 2.h" \
	"$$H/hardware/storage medium/optical disc/Wii U Optical Disc.h" \
	"$$H/hardware/video/CGA.h" \
	"$$H/hardware/video/EGA.h" \
	"$$H/hardware/video/Hercules.h" \
	"$$H/hardware/video/Super VGA.h" \
	"$$H/hardware/video/VBE.h" \
	"$$H/hardware/video/VGA.h" \
	"$$H/inspection/C++.h" \
	"$$H/inspection/C.h" \
	"$$H/inspection/CPU.h" \
	"$$H/inspection/OS.h" \
	"$$H/inspection/Objective-C.h" \
	"$$H/inspection/build.h" \
	"$$H/inspection/character set.h" \
	"$$H/inspection/compiler.h" \
	"$$H/inspection/data model.h" \
	"$$H/inspection/floating point.h" \
	"$$H/inspection/language.h" \
	"$$H/inspection/private/C++/C++03.h" \
	"$$H/inspection/private/C++/C++07 TR1.h" \
	"$$H/inspection/private/C++/C++11.h" \
	"$$H/inspection/private/C++/C++14.h" \
	"$$H/inspection/private/C++/C++17.h" \
	"$$H/inspection/private/C++/C++85.h" \
	"$$H/inspection/private/C++/C++89.h" \
	"$$H/inspection/private/C++/C++98.h" \
	"$$H/inspection/private/C/C11.h" \
	"$$H/inspection/private/C/C89.h" \
	"$$H/inspection/private/C/C90.h" \
	"$$H/inspection/private/C/C94.h" \
	"$$H/inspection/private/C/C99.h" \
	"$$H/inspection/private/C/KR C.h" \
	"$$H/inspection/private/OS/Linux.h" \
	"$$H/inspection/private/OS/MS-DOS.h" \
	"$$H/inspection/private/OS/Mac OS X.h" \
	"$$H/inspection/private/OS/Windows.h" \
	"$$H/inspection/private/OS/iPhone OS.h" \
	"$$H/inspection/private/Objective-C/Objective-C v1.0.h" \
	"$$H/inspection/private/Objective-C/Objective-C v2.0.h" \
	"$$H/inspection/private/compiler/Apple LLVM.h" \
	"$$H/inspection/private/compiler/Clang.h" \
	"$$H/inspection/private/compiler/GCC.h" \
	"$$H/inspection/private/compiler/Visual C++.h" \
	"$$H/inspection/private/compiler/generic.h" \
	"$$H/inspection/private/compiler/template.h" \
	"$$H/inspection/program.h" \
	"$$H/keys/C++.h" \
	"$$H/keys/C.h" \
	"$$H/keys/OS.h" \
	"$$H/keys/Objective-C.h" \
	"$$H/keys/access mode.h" \
	"$$H/keys/character set.h" \
	"$$H/keys/color.h" \
	"$$H/keys/compiler.h" \
	"$$H/keys/data model.h" \
	"$$H/keys/endianness.h" \
	"$$H/keys/floating point.h" \
	"$$H/keys/hardware/CPU/ISA.h" \
	"$$H/keys/hardware/CPU/architecture.h" \
	"$$H/keys/hardware/CPU/family.h" \
	"$$H/keys/hardware/machine/model/ZX Spectrum.h" \
	"$$H/keys/hardware/machine/platform.h" \
	"$$H/keys/introspection.h" \
	"$$H/keys/language.h" \
	"$$H/keys/layout.h" \
	"$$H/keys/map.h" \
	"$$H/keys/mathematics/geometry.h" \
	"$$H/keys/numeral system.h" \
	"$$H/keys/order.h" \
	"$$H/keys/program.h" \
	"$$H/keys/science/chemical elements.h" \
	"$$H/keys/science/crystallography.h" \
	"$$H/keys/science/electricity.h" \
	"$$H/keys/science/magnetism.h" \
	"$$H/keys/status.h" \
	"$$H/keys/text.h" \
	"$$H/keys/value.h" \
	"$$H/macros/arguments.h" \
	"$$H/macros/bits.h" \
	"$$H/macros/casting.h" \
	"$$H/macros/character.h" \
	"$$H/macros/color.h" \
	"$$H/macros/date.h" \
	"$$H/macros/inspection.h" \
	"$$H/macros/key.h" \
	"$$H/macros/language.h" \
	"$$H/macros/mathematics.h" \
	"$$H/macros/members.h" \
	"$$H/macros/node.h" \
	"$$H/macros/pointer.h" \
	"$$H/macros/preprocessor.h" \
	"$$H/macros/slot.h" \
	"$$H/macros/structure.h" \
	"$$H/macros/templating.h" \
	"$$H/macros/unit.h" \
	"$$H/macros/value.h" \
	"$$H/macros/version.h" \
	"$$H/network/2/Ethernet.h" \
	"$$H/network/2/PPP.h" \
	"$$H/network/2/PPTP.h" \
	"$$H/network/2/SLIP.h" \
	"$$H/network/3/ICMP.h" \
	"$$H/network/3/IGMP.h" \
	"$$H/network/3/IP.h" \
	"$$H/network/3/IPX.h" \
	"$$H/network/4/TCP.h" \
	"$$H/network/4/UDP.h" \
	"$$H/network/5/ADSP.h" \
	"$$H/network/5/L2F.h" \
	"$$H/network/5/L2TP.h" \
	"$$H/network/5/NetBIOS.h" \
	"$$H/network/5/PAP.h" \
	"$$H/network/5/RTP.h" \
	"$$H/network/5/SIP.h" \
	"$$H/network/5/SOCKS.h" \
	"$$H/network/5/SSH.h" \
	"$$H/network/7/BitTorrent.h" \
	"$$H/network/7/DHCP.h" \
	"$$H/network/7/DNS.h" \
	"$$H/network/7/ED2K.h" \
	"$$H/network/7/FTP.h" \
	"$$H/network/7/HTTP.h" \
	"$$H/network/7/IRC.h" \
	"$$H/network/7/NNTP.h" \
	"$$H/network/7/NTP.h" \
	"$$H/network/7/POP3.h" \
	"$$H/network/7/RADIUS.h" \
	"$$H/network/7/SMTP.h" \
	"$$H/network/7/SNMP.h" \
	"$$H/network/7/SSH.h" \
	"$$H/types/arguments.h" \
	"$$H/types/base.h" \
	"$$H/types/buffering.h" \
	"$$H/types/data.h" \
	"$$H/types/generic functions.h" \
	"$$H/types/introspection.h" \
	"$$H/types/mathematics.h" \
	"$$H/types/text.h" \
	"$$H/types/time.h" \
	"$$HPP/classes/base/Function.hpp" \
	"$$HPP/classes/base/Range.hpp" \
	"$$HPP/classes/base/Status.hpp" \
	"$$HPP/classes/base/Value2D.hpp" \
	"$$HPP/classes/base/Value3D.hpp" \
	"$$HPP/classes/buffering/RingBuffer.hpp" \
	"$$HPP/classes/buffering/TripleBuffer.hpp" \
	"$$HPP/classes/mathematics/geometry/euclidean/AABB.hpp" \
	"$$HPP/classes/mathematics/geometry/euclidean/AABR.hpp" \
	"$$HPP/classes/mathematics/geometry/euclidean/Box.hpp" \
	"$$HPP/classes/mathematics/geometry/euclidean/Circle.hpp" \
	"$$HPP/classes/mathematics/geometry/euclidean/Line2D.hpp" \
	"$$HPP/classes/mathematics/geometry/euclidean/Line3D.hpp" \
	"$$HPP/classes/mathematics/geometry/euclidean/Rectangle.hpp" \
	"$$HPP/classes/mathematics/geometry/euclidean/Sphere.hpp" \
	"$$HPP/classes/memory/Shared.hpp" \
	"$$HPP/classes/time/Attotime.hpp" \
	"$$HPP/classes/time/Nanotime.hpp" \
	"$$HPP/functions/base/value.hpp" \
	"$$HPP/functions/casting.hpp" \
	"$$HPP/macros/language.hpp" \
	"$$HPP/macros/super.hpp" \
	"$$HPP/macros/type selector.hpp" \
	"$$HPP/traits/Type.hpp" \
	"$$HPP/traits/TypeOrVoid.hpp" \
	"$$HPP/traits/conditionals.hpp" \
	"$$HPP/traits/mathematics.hpp" \
	"$$HPP/types/base.hpp" \

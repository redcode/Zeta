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
	"$$H/constants/base.h" \
	"$$H/constants/numbers.h" \
	"$$H/constants/science/chemical elements.h" \
	"$$H/constants/version.h" \
	"$$H/formats/archive/9z.h" \
	"$$H/formats/character set/ASCII.h" \
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
	"$$H/formats/character set/Unicode.h" \
	"$$H/formats/data model/ILP32.h" \
	"$$H/formats/data model/ILP64.h" \
	"$$H/formats/data model/LLP64.h" \
	"$$H/formats/data model/LP32.h" \
	"$$H/formats/data model/LP64.h" \
	"$$H/formats/data model/SILP64.h" \
	"$$H/formats/file system/FAT12.h" \
	"$$H/formats/floating point/IEEE 754.h" \
	"$$H/formats/floating point/Intel.h" \
	"$$H/formats/image/ICNS.h" \
	"$$H/formats/multimedia container/Creative Voice.h" \
	"$$H/formats/multimedia container/Microsoft Wave.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/ACH.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/FRZ.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/PRG.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SEM.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SIT.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SNA.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SNP.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/SP.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/Z80.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/ZX.h" \
	"$$H/formats/snapshot/machine/computer/ZX Spectrum/ZX82.h" \
	"$$H/formats/storage medium image/NES Game Pak/UNIF.h" \
	"$$H/formats/storage medium image/NES Game Pak/iNES.h" \
	"$$H/formats/storage medium image/audio/TAP.h" \
	"$$H/formats/storage medium image/audio/TZX.h" \
	"$$H/formats/storage medium image/audio/Warajevo TAP.h" \
	"$$H/formats/storage medium image/floppy disk/FDI.h" \
	"$$H/functions/base/Z2DValue.h" \
	"$$H/functions/base/Z3DValue.h" \
	"$$H/functions/base/ZRange.h" \
	"$$H/functions/base/all.h" \
	"$$H/functions/base/character.h" \
	"$$H/functions/base/constructors.h" \
	"$$H/functions/base/value.h" \
	"$$H/functions/buffering/ZRingBuffer.h" \
	"$$H/functions/buffering/ZTripleBuffer.h" \
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
	"$$H/functions/time/date.h" \
	"$$H/hardware/BUS/AGP.h" \
	"$$H/hardware/BUS/USB.h" \
	"$$H/hardware/CPU/architecture/6502.h" \
	"$$H/hardware/CPU/architecture/Z80.h" \
	"$$H/hardware/CPU/architecture/i4004.h" \
	"$$H/hardware/PSG/General Instrument/AY-3-891x.h" \
	"$$H/hardware/VDC/Ricoh/RP2C0x.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/Inves Spectrum +.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/Pentagon.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/Scorpion.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum + 128K.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +2.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +2A.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +3.h" \
	"$$H/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum.h" \
	"$$H/hardware/machine/model/console/Nintendo Entertainment System/NES-001 (NTSC).h" \
	"$$H/hardware/machine/model/console/Nintendo Entertainment System/NES-001 (PAL).h" \
	"$$H/hardware/machine/platform/computer/ZX Spectrum.h" \
	"$$H/hardware/machine/platform/console/Game Boy.h" \
	"$$H/hardware/machine/platform/console/Nintendo Entertainment System.h" \
	"$$H/hardware/storage medium/ROM cartridge/SNES Game Pak.h" \
	"$$H/inspection/C++.h" \
	"$$H/inspection/C++/completion.h" \
	"$$H/inspection/C++/modules/C++03.h" \
	"$$H/inspection/C++/modules/C++11.h" \
	"$$H/inspection/C++/modules/C++14.h" \
	"$$H/inspection/C++/modules/C++17.h" \
	"$$H/inspection/C++/modules/C++85.h" \
	"$$H/inspection/C++/modules/C++89.h" \
	"$$H/inspection/C++/modules/C++98.h" \
	"$$H/inspection/C.h" \
	"$$H/inspection/C/completion.h" \
	"$$H/inspection/C/modules/C11.h" \
	"$$H/inspection/C/modules/C89.h" \
	"$$H/inspection/C/modules/C90.h" \
	"$$H/inspection/C/modules/C94.h" \
	"$$H/inspection/C/modules/C99.h" \
	"$$H/inspection/C/modules/KR C.h" \
	"$$H/inspection/CPU.h" \
	"$$H/inspection/CPU/completion.h" \
	"$$H/inspection/CPU/detection.h" \
	"$$H/inspection/CPU/modules/AArch32.h" \
	"$$H/inspection/CPU/modules/AArch64.h" \
	"$$H/inspection/CPU/modules/x86-32.h" \
	"$$H/inspection/CPU/modules/x86-64.h" \
	"$$H/inspection/OS.h" \
	"$$H/inspection/OS/completion.h" \
	"$$H/inspection/OS/detection.h" \
	"$$H/inspection/OS/modules/Linux.h" \
	"$$H/inspection/OS/modules/MS-DOS.h" \
	"$$H/inspection/OS/modules/Mac OS X.h" \
	"$$H/inspection/OS/modules/Windows.h" \
	"$$H/inspection/OS/modules/iPhone OS.h" \
	"$$H/inspection/Objective-C.h" \
	"$$H/inspection/Objective-C/completion.h" \
	"$$H/inspection/Objective-C/modules/Objective-C v1.0.h" \
	"$$H/inspection/Objective-C/modules/Objective-C v2.0.h" \
	"$$H/inspection/build.h" \
	"$$H/inspection/character set.h" \
	"$$H/inspection/compiler.h" \
	"$$H/inspection/compiler/completion.h" \
	"$$H/inspection/compiler/modules/Apple LLVM.h" \
	"$$H/inspection/compiler/modules/Clang.h" \
	"$$H/inspection/compiler/modules/GCC.h" \
	"$$H/inspection/compiler/modules/Visual C++.h" \
	"$$H/inspection/compiler/modules/generic.h" \
	"$$H/inspection/compiler/modules/template.h" \
	"$$H/inspection/data model.h" \
	"$$H/inspection/data model/deduction.h" \
	"$$H/inspection/data model/detection.h" \
	"$$H/inspection/floating point.h" \
	"$$H/inspection/language.h" \
	"$$H/keys/C++.h" \
	"$$H/keys/C.h" \
	"$$H/keys/OS.h" \
	"$$H/keys/Objective-C.h" \
	"$$H/keys/character set.h" \
	"$$H/keys/compiler.h" \
	"$$H/keys/data model.h" \
	"$$H/keys/endianness.h" \
	"$$H/keys/floating point.h" \
	"$$H/keys/hardware/CPU/architecture.h" \
	"$$H/keys/language.h" \
	"$$H/keys/layout.h" \
	"$$H/keys/mathematics/geometry.h" \
	"$$H/keys/order.h" \
	"$$H/keys/program.h" \
	"$$H/keys/science/chemical elements.h" \
	"$$H/keys/science/electricity.h" \
	"$$H/keys/science/magnetism.h" \
	"$$H/keys/status.h" \
	"$$H/keys/text.h" \
	"$$H/keys/value.h" \
	"$$H/macros/arguments.h" \
	"$$H/macros/casting.h" \
	"$$H/macros/character.h" \
	"$$H/macros/conditionals.h" \
	"$$H/macros/date.h" \
	"$$H/macros/key.h" \
	"$$H/macros/language.h" \
	"$$H/macros/members.h" \
	"$$H/macros/node.h" \
	"$$H/macros/pasting.h" \
	"$$H/macros/pointer.h" \
	"$$H/macros/repetition.h" \
	"$$H/macros/slot.h" \
	"$$H/macros/structure.h" \
	"$$H/macros/templating.h" \
	"$$H/macros/tokens.h" \
	"$$H/macros/type enumeration.h" \
	"$$H/macros/value.h" \
	"$$H/macros/variadic pasting.h" \
	"$$H/macros/variadic selection.h" \
	"$$H/macros/variadic.h" \
	"$$H/macros/version.h" \
	"$$H/network/3/IP.h" \
	"$$H/network/4/TCP.h" \
	"$$H/network/4/UDP.h" \
	"$$H/network/7/ED2K.h" \
	"$$H/network/7/HTTP.h" \
	"$$H/types/arguments.h" \
	"$$H/types/base.h" \
	"$$H/types/buffering.h" \
	"$$H/types/data.h" \
	"$$H/types/generic functions.h" \
	"$$H/types/mathematics.h" \
	"$$H/types/text.h" \
	"$$H/types/time.h" \
	"$$HPP/classes/base/Function.hpp" \
	"$$HPP/classes/base/InitializerList.hpp" \
	"$$HPP/classes/base/Pair.hpp" \
	"$$HPP/classes/base/Range.hpp" \
	"$$HPP/classes/base/Status.hpp" \
	"$$HPP/classes/base/Tuple.hpp" \
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
	"$$HPP/macros/type selection.hpp" \
	"$$HPP/traits/SelectType.hpp" \
	"$$HPP/traits/Type.hpp" \
	"$$HPP/traits/TypeOrVoid.hpp" \
	"$$HPP/traits/base.hpp" \
	"$$HPP/traits/conditionals.hpp" \
	"$$HPP/traits/mathematics.hpp" \
	"$$HPP/types/base.hpp" \

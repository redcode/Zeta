/* Q API - compatibility/OS X/NSGeometry+Q.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2013 RedCode Software. All rights reserved. */

#ifndef __Q_compatibility_OS_X_NSGeometry_plus_Q_h
#define __Q_compatibility_OS_X_NSGeometry_plus_Q_h

#import <Foundation/NSGeometry.h>
#import <Q/functions/Q2DValue.h>
#import <Q/functions/mathematics.h>

typedef union {
	Q2D	q;
	NSPoint nspoint;
	CGPoint cgpoint;
	NSSize	nssize;
	CGSize	cgsize;
} __QNS2D;

typedef union {
	QRectangle	q;
	NSRect		nsrect;
	CGRect		cgrect;
} __QNSRectangle;

NS_INLINE NSPoint	QToNSPoint(Q2D	      value)	 {return ((__QNS2D	  *)&value)->nspoint;	}
NS_INLINE CGPoint	QToCGPoint(Q2D	      value)	 {return ((__QNS2D	  *)&value)->cgpoint;	}
NS_INLINE NSSize	QToNSSize (Q2D	      value)	 {return ((__QNS2D	  *)&value)->nssize;	}
NS_INLINE CGSize	QToCGSize (Q2D	      value)	 {return ((__QNS2D	  *)&value)->cgsize;	}
NS_INLINE Q2D		NSPointToQ(NSPoint    value)	 {return ((__QNS2D	  *)&value)->q;		}
NS_INLINE Q2D		CGPointToQ(CGPoint    value)	 {return ((__QNS2D	  *)&value)->q;		}
NS_INLINE Q2D		NSSizeToQ (NSSize     value)	 {return ((__QNS2D	  *)&value)->q;		}
NS_INLINE Q2D		CGSizeToQ (CGSize     value)	 {return ((__QNS2D	  *)&value)->q;		}
NS_INLINE QRectangle	NSRectToQ (NSRect     rectangle) {return ((__QNSRectangle *)&rectangle)->q;	}
NS_INLINE QRectangle	CGRectToQ (CGRect     rectangle) {return ((__QNSRectangle *)&rectangle)->q;	}
NS_INLINE NSRect	QToNSRect (QRectangle rectangle) {return ((__QNSRectangle *)&rectangle)->nsrect;}
NS_INLINE CGRect	QToCGRect (QRectangle rectangle) {return ((__QNSRectangle *)&rectangle)->cgrect;}

#define NSSizeAdd(	a, b)	QToNSSize(q_2d_add	(NSSizeToQ(a), NSSizeToQ(b)))
#define NSSizeAddQ(	a, b)	QToNSSize(q_2d_add	(NSSizeToQ(a),		 b ))
#define NSSizeSubtract(	a, b)	QToNSSize(q_2d_subtract (NSSizeToQ(a), NSSizeToQ(b)))
#define NSSizeSubtractQ(a, b)	QToNSSize(q_2d_subtract (NSSizeToQ(a),		 b ))
#define NSSizeFit(	a, b)	QToNSSize(q_2d_fit	(NSSizeToQ(a), NSSizeToQ(b)))
#define NSSizeFitQ(	a, b)	QToNSSize(q_2d_fit	(NSSizeToQ(a),		 b ))
#define NSSizeContains(	a, b)		  q_2d_contains	(NSSizeToQ(a), NSSizeToQ(b))
#define NSSizeContainsQ(a, b)		  q_2d_contains	(NSSizeToQ(a), 		 b )

#define QAddNSSize(	a, b)	QToNSSize(q_2d_add	(	   a , NSSizeToQ(b)))
#define QSubtractNSSize(a, b)	QToNSSize(q_2d_subtract	(	   a , NSSizeToQ(b)))
#define QFitNSSize(	a, b)	QToNSSize(q_2d_fit	(	   a , NSSizeToQ(b)))
#define QContainsNSSize(a, b)		  q_2d_contains	(	   a , NSSizeToQ(b))

#endif /* __Q_compatibility_OS_X_NSGeometry_plus_Q_h */


#ifdef _useclapack_h

#ifndef __CLAPACK_H
#define __CLAPACK_H

#include "f2c.h"
 
/* Subroutine */ extern "C" int cbdsqr_(char *uplo, integer *n, integer *ncvt, integer *
	nru, integer *ncc, real *d__, real *e, complex *vt, integer *ldvt, 
	complex *u, integer *ldu, complex *c__, integer *ldc, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int cgbbrd_(char *vect, integer *m, integer *n, integer *ncc,
	 integer *kl, integer *ku, complex *ab, integer *ldab, real *d__, 
	real *e, complex *q, integer *ldq, complex *pt, integer *ldpt, 
	complex *c__, integer *ldc, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgbcon_(char *norm, integer *n, integer *kl, integer *ku,
	 complex *ab, integer *ldab, integer *ipiv, real *anorm, real *rcond, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgbequ_(integer *m, integer *n, integer *kl, integer *ku,
	 complex *ab, integer *ldab, real *r__, real *c__, real *rowcnd, real 
	*colcnd, real *amax, integer *info);
 
/* Subroutine */ extern "C" int cgbrfs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, complex *ab, integer *ldab, complex *afb, integer *
	ldafb, integer *ipiv, complex *b, integer *ldb, complex *x, integer *
	ldx, real *ferr, real *berr, complex *work, real *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int cgbsv_(integer *n, integer *kl, integer *ku, integer *
	nrhs, complex *ab, integer *ldab, integer *ipiv, complex *b, integer *
	ldb, integer *info);
 
/* Subroutine */ extern "C" int cgbsvx_(char *fact, char *trans, integer *n, integer *kl,
	 integer *ku, integer *nrhs, complex *ab, integer *ldab, complex *afb,
	 integer *ldafb, integer *ipiv, char *equed, real *r__, real *c__, 
	complex *b, integer *ldb, complex *x, integer *ldx, real *rcond, real 
	*ferr, real *berr, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgbtf2_(integer *m, integer *n, integer *kl, integer *ku,
	 complex *ab, integer *ldab, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int cgbtrf_(integer *m, integer *n, integer *kl, integer *ku,
	 complex *ab, integer *ldab, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int cgbtrs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, complex *ab, integer *ldab, integer *ipiv, complex 
	*b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cgebak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, real *scale, integer *m, complex *v, integer *ldv, 
	integer *info);
 
/* Subroutine */ extern "C" int cgebal_(char *job, integer *n, complex *a, integer *lda, 
	integer *ilo, integer *ihi, real *scale, integer *info);
 
/* Subroutine */ extern "C" int cgebd2_(integer *m, integer *n, complex *a, integer *lda,
	 real *d__, real *e, complex *tauq, complex *taup, complex *work, 
	integer *info);
 
/* Subroutine */ extern "C" int cgebrd_(integer *m, integer *n, complex *a, integer *lda,
	 real *d__, real *e, complex *tauq, complex *taup, complex *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cgecon_(char *norm, integer *n, complex *a, integer *lda,
	 real *anorm, real *rcond, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgeequ_(integer *m, integer *n, complex *a, integer *lda,
	 real *r__, real *c__, real *rowcnd, real *colcnd, real *amax, 
	integer *info);
 
/* Subroutine */ extern "C" int cgees_(char *jobvs, char *sort, L_fp select, integer *n, 
	complex *a, integer *lda, integer *sdim, complex *w, complex *vs, 
	integer *ldvs, complex *work, integer *lwork, real *rwork, logical *
	bwork, integer *info);
 
/* Subroutine */ extern "C" int cgeesx_(char *jobvs, char *sort, L_fp select, char *
	sense, integer *n, complex *a, integer *lda, integer *sdim, complex *
	w, complex *vs, integer *ldvs, real *rconde, real *rcondv, complex *
	work, integer *lwork, real *rwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int cgeev_(char *jobvl, char *jobvr, integer *n, complex *a, 
	integer *lda, complex *w, complex *vl, integer *ldvl, complex *vr, 
	integer *ldvr, complex *work, integer *lwork, real *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int cgeevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, complex *a, integer *lda, complex *w, complex *vl, 
	integer *ldvl, complex *vr, integer *ldvr, integer *ilo, integer *ihi,
	 real *scale, real *abnrm, real *rconde, real *rcondv, complex *work, 
	integer *lwork, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgegs_(char *jobvsl, char *jobvsr, integer *n, complex *
	a, integer *lda, complex *b, integer *ldb, complex *alpha, complex *
	beta, complex *vsl, integer *ldvsl, complex *vsr, integer *ldvsr, 
	complex *work, integer *lwork, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgegv_(char *jobvl, char *jobvr, integer *n, complex *a, 
	integer *lda, complex *b, integer *ldb, complex *alpha, complex *beta,
	 complex *vl, integer *ldvl, complex *vr, integer *ldvr, complex *
	work, integer *lwork, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgehd2_(integer *n, integer *ilo, integer *ihi, complex *
	a, integer *lda, complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cgehrd_(integer *n, integer *ilo, integer *ihi, complex *
	a, integer *lda, complex *tau, complex *work, integer *lwork, integer 
	*info);
 
/* Subroutine */ extern "C" int cgelq2_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cgelqf_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cgels_(char *trans, integer *m, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *b, integer *ldb, complex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cgelsx_(integer *m, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *b, integer *ldb, integer *jpvt, real *rcond,
	 integer *rank, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgelsy_(integer *m, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *b, integer *ldb, integer *jpvt, real *rcond,
	 integer *rank, complex *work, integer *lwork, real *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int cgeql2_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cgeqlf_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cgeqp3_(integer *m, integer *n, complex *a, integer *lda,
	 integer *jpvt, complex *tau, complex *work, integer *lwork, real *
	rwork, integer *info);
 
/* Subroutine */ extern "C" int cgeqpf_(integer *m, integer *n, complex *a, integer *lda,
	 integer *jpvt, complex *tau, complex *work, real *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int cgeqr2_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cgeqrf_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cgerfs_(char *trans, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *af, integer *ldaf, integer *ipiv, complex *
	b, integer *ldb, complex *x, integer *ldx, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgerq2_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cgerqf_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cgesc2_(integer *n, complex *a, integer *lda, complex *
	rhs, integer *ipiv, integer *jpiv, real *scale);
 
/* Subroutine */ extern "C" int cgesv_(integer *n, integer *nrhs, complex *a, integer *
	lda, integer *ipiv, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cgesvx_(char *fact, char *trans, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, char *equed, real *r__, real *c__, complex *b, integer *ldb, 
	complex *x, integer *ldx, real *rcond, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgetc2_(integer *n, complex *a, integer *lda, integer *
	ipiv, integer *jpiv, integer *info);
 
/* Subroutine */ extern "C" int cgetf2_(integer *m, integer *n, complex *a, integer *lda,
	 integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int cgetrf_(integer *m, integer *n, complex *a, integer *lda,
	 integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int cgetri_(integer *n, complex *a, integer *lda, integer *
	ipiv, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cgetrs_(char *trans, integer *n, integer *nrhs, complex *
	a, integer *lda, integer *ipiv, complex *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int cggbak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, real *lscale, real *rscale, integer *m, complex *v, 
	integer *ldv, integer *info);
 
/* Subroutine */ extern "C" int cggbal_(char *job, integer *n, complex *a, integer *lda, 
	complex *b, integer *ldb, integer *ilo, integer *ihi, real *lscale, 
	real *rscale, real *work, integer *info);
 
/* Subroutine */ extern "C" int cgges_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	selctg, integer *n, complex *a, integer *lda, complex *b, integer *
	ldb, integer *sdim, complex *alpha, complex *beta, complex *vsl, 
	integer *ldvsl, complex *vsr, integer *ldvsr, complex *work, integer *
	lwork, real *rwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int cggesx_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	selctg, char *sense, integer *n, complex *a, integer *lda, complex *b,
	 integer *ldb, integer *sdim, complex *alpha, complex *beta, complex *
	vsl, integer *ldvsl, complex *vsr, integer *ldvsr, real *rconde, real 
	*rcondv, complex *work, integer *lwork, real *rwork, integer *iwork, 
	integer *liwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int cggev_(char *jobvl, char *jobvr, integer *n, complex *a, 
	integer *lda, complex *b, integer *ldb, complex *alpha, complex *beta,
	 complex *vl, integer *ldvl, complex *vr, integer *ldvr, complex *
	work, integer *lwork, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cggevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, complex *a, integer *lda, complex *b, integer *ldb,
	 complex *alpha, complex *beta, complex *vl, integer *ldvl, complex *
	vr, integer *ldvr, integer *ilo, integer *ihi, real *lscale, real *
	rscale, real *abnrm, real *bbnrm, real *rconde, real *rcondv, complex 
	*work, integer *lwork, real *rwork, integer *iwork, logical *bwork, 
	integer *info);
 
/* Subroutine */ extern "C" int cggglm_(integer *n, integer *m, integer *p, complex *a, 
	integer *lda, complex *b, integer *ldb, complex *d__, complex *x, 
	complex *y, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cgghrd_(char *compq, char *compz, integer *n, integer *
	ilo, integer *ihi, complex *a, integer *lda, complex *b, integer *ldb,
	 complex *q, integer *ldq, complex *z__, integer *ldz, integer *info);
 
/* Subroutine */ extern "C" int cgglse_(integer *m, integer *n, integer *p, complex *a, 
	integer *lda, complex *b, integer *ldb, complex *c__, complex *d__, 
	complex *x, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cggqrf_(integer *n, integer *m, integer *p, complex *a, 
	integer *lda, complex *taua, complex *b, integer *ldb, complex *taub, 
	complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cggrqf_(integer *m, integer *p, integer *n, complex *a, 
	integer *lda, complex *taua, complex *b, integer *ldb, complex *taub, 
	complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cggsvd_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *n, integer *p, integer *k, integer *l, complex *a, integer *
	lda, complex *b, integer *ldb, real *alpha, real *beta, complex *u, 
	integer *ldu, complex *v, integer *ldv, complex *q, integer *ldq, 
	complex *work, real *rwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int cggsvp_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, complex *a, integer *lda, complex *b, integer 
	*ldb, real *tola, real *tolb, integer *k, integer *l, complex *u, 
	integer *ldu, complex *v, integer *ldv, complex *q, integer *ldq, 
	integer *iwork, real *rwork, complex *tau, complex *work, integer *
	info);
 
/* Subroutine */ extern "C" int cgtcon_(char *norm, integer *n, complex *dl, complex *
	d__, complex *du, complex *du2, integer *ipiv, real *anorm, real *
	rcond, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cgtrfs_(char *trans, integer *n, integer *nrhs, complex *
	dl, complex *d__, complex *du, complex *dlf, complex *df, complex *
	duf, complex *du2, integer *ipiv, complex *b, integer *ldb, complex *
	x, integer *ldx, real *ferr, real *berr, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int cgtsv_(integer *n, integer *nrhs, complex *dl, complex *
	d__, complex *du, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cgtsvx_(char *fact, char *trans, integer *n, integer *
	nrhs, complex *dl, complex *d__, complex *du, complex *dlf, complex *
	df, complex *duf, complex *du2, integer *ipiv, complex *b, integer *
	ldb, complex *x, integer *ldx, real *rcond, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cgttrf_(integer *n, complex *dl, complex *d__, complex *
	du, complex *du2, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int cgttrs_(char *trans, integer *n, integer *nrhs, complex *
	dl, complex *d__, complex *du, complex *du2, integer *ipiv, complex *
	b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cgtts2_(integer *itrans, integer *n, integer *nrhs, 
	complex *dl, complex *d__, complex *du, complex *du2, integer *ipiv, 
	complex *b, integer *ldb);
 
/* Subroutine */ extern "C" int chbev_(char *jobz, char *uplo, integer *n, integer *kd, 
	complex *ab, integer *ldab, real *w, complex *z__, integer *ldz, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int chbevd_(char *jobz, char *uplo, integer *n, integer *kd, 
	complex *ab, integer *ldab, real *w, complex *z__, integer *ldz, 
	complex *work, integer *lwork, real *rwork, integer *lrwork, integer *
	iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int chbevx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *kd, complex *ab, integer *ldab, complex *q, integer *ldq, 
	real *vl, real *vu, integer *il, integer *iu, real *abstol, integer *
	m, real *w, complex *z__, integer *ldz, complex *work, real *rwork, 
	integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int chbgst_(char *vect, char *uplo, integer *n, integer *ka, 
	integer *kb, complex *ab, integer *ldab, complex *bb, integer *ldbb, 
	complex *x, integer *ldx, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int chbgv_(char *jobz, char *uplo, integer *n, integer *ka, 
	integer *kb, complex *ab, integer *ldab, complex *bb, integer *ldbb, 
	real *w, complex *z__, integer *ldz, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int chbgvx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *ka, integer *kb, complex *ab, integer *ldab, complex *bb, 
	integer *ldbb, complex *q, integer *ldq, real *vl, real *vu, integer *
	il, integer *iu, real *abstol, integer *m, real *w, complex *z__, 
	integer *ldz, complex *work, real *rwork, integer *iwork, integer *
	ifail, integer *info);
 
/* Subroutine */ extern "C" int chbtrd_(char *vect, char *uplo, integer *n, integer *kd, 
	complex *ab, integer *ldab, real *d__, real *e, complex *q, integer *
	ldq, complex *work, integer *info);
 
/* Subroutine */ extern "C" int checon_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *ipiv, real *anorm, real *rcond, complex *work, integer *
	info);
 
/* Subroutine */ extern "C" int cheev_(char *jobz, char *uplo, integer *n, complex *a, 
	integer *lda, real *w, complex *work, integer *lwork, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int cheevd_(char *jobz, char *uplo, integer *n, complex *a, 
	integer *lda, real *w, complex *work, integer *lwork, real *rwork, 
	integer *lrwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int cheevr_(char *jobz, char *range, char *uplo, integer *n, 
	complex *a, integer *lda, real *vl, real *vu, integer *il, integer *
	iu, real *abstol, integer *m, real *w, complex *z__, integer *ldz, 
	integer *isuppz, complex *work, integer *lwork, real *rwork, integer *
	lrwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int cheevx_(char *jobz, char *range, char *uplo, integer *n, 
	complex *a, integer *lda, real *vl, real *vu, integer *il, integer *
	iu, real *abstol, integer *m, real *w, complex *z__, integer *ldz, 
	complex *work, integer *lwork, real *rwork, integer *iwork, integer *
	ifail, integer *info);
 
/* Subroutine */ extern "C" int chegs2_(integer *itype, char *uplo, integer *n, complex *
	a, integer *lda, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int chegst_(integer *itype, char *uplo, integer *n, complex *
	a, integer *lda, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int chegv_(integer *itype, char *jobz, char *uplo, integer *
	n, complex *a, integer *lda, complex *b, integer *ldb, real *w, 
	complex *work, integer *lwork, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int chegvd_(integer *itype, char *jobz, char *uplo, integer *
	n, complex *a, integer *lda, complex *b, integer *ldb, real *w, 
	complex *work, integer *lwork, real *rwork, integer *lrwork, integer *
	iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int chegvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, complex *a, integer *lda, complex *b, integer *ldb, 
	real *vl, real *vu, integer *il, integer *iu, real *abstol, integer *
	m, real *w, complex *z__, integer *ldz, complex *work, integer *lwork,
	 real *rwork, integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int cherfs_(char *uplo, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *af, integer *ldaf, integer *ipiv, complex *
	b, integer *ldb, complex *x, integer *ldx, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int chesv_(char *uplo, integer *n, integer *nrhs, complex *a,
	 integer *lda, integer *ipiv, complex *b, integer *ldb, complex *work,
	 integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int chesvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, complex *b, integer *ldb, complex *x, integer *ldx, real *rcond,
	 real *ferr, real *berr, complex *work, integer *lwork, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int chetf2_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int chetrd_(char *uplo, integer *n, complex *a, integer *lda,
	 real *d__, real *e, complex *tau, complex *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int chetrf_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *ipiv, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int chetri_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *ipiv, complex *work, integer *info);
 
/* Subroutine */ extern "C" int chetrs_(char *uplo, integer *n, integer *nrhs, complex *
	a, integer *lda, integer *ipiv, complex *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int chgeqz_(char *job, char *compq, char *compz, integer *n, 
	integer *ilo, integer *ihi, complex *a, integer *lda, complex *b, 
	integer *ldb, complex *alpha, complex *beta, complex *q, integer *ldq,
	 complex *z__, integer *ldz, complex *work, integer *lwork, real *
	rwork, integer *info);
 
/* Subroutine */ extern "C" int chpcon_(char *uplo, integer *n, complex *ap, integer *
	ipiv, real *anorm, real *rcond, complex *work, integer *info);
 
/* Subroutine */ extern "C" int chpev_(char *jobz, char *uplo, integer *n, complex *ap, 
	real *w, complex *z__, integer *ldz, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int chpevd_(char *jobz, char *uplo, integer *n, complex *ap, 
	real *w, complex *z__, integer *ldz, complex *work, integer *lwork, 
	real *rwork, integer *lrwork, integer *iwork, integer *liwork, 
	integer *info);
 
/* Subroutine */ extern "C" int chpevx_(char *jobz, char *range, char *uplo, integer *n, 
	complex *ap, real *vl, real *vu, integer *il, integer *iu, real *
	abstol, integer *m, real *w, complex *z__, integer *ldz, complex *
	work, real *rwork, integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int chpgst_(integer *itype, char *uplo, integer *n, complex *
	ap, complex *bp, integer *info);
 
/* Subroutine */ extern "C" int chpgv_(integer *itype, char *jobz, char *uplo, integer *
	n, complex *ap, complex *bp, real *w, complex *z__, integer *ldz, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int chpgvd_(integer *itype, char *jobz, char *uplo, integer *
	n, complex *ap, complex *bp, real *w, complex *z__, integer *ldz, 
	complex *work, integer *lwork, real *rwork, integer *lrwork, integer *
	iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int chpgvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, complex *ap, complex *bp, real *vl, real *vu, 
	integer *il, integer *iu, real *abstol, integer *m, real *w, complex *
	z__, integer *ldz, complex *work, real *rwork, integer *iwork, 
	integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int chprfs_(char *uplo, integer *n, integer *nrhs, complex *
	ap, complex *afp, integer *ipiv, complex *b, integer *ldb, complex *x,
	 integer *ldx, real *ferr, real *berr, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int chpsv_(char *uplo, integer *n, integer *nrhs, complex *
	ap, integer *ipiv, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int chpsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *ap, complex *afp, integer *ipiv, complex *b, integer *
	ldb, complex *x, integer *ldx, real *rcond, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int chptrd_(char *uplo, integer *n, complex *ap, real *d__, 
	real *e, complex *tau, integer *info);
 
/* Subroutine */ extern "C" int chptrf_(char *uplo, integer *n, complex *ap, integer *
	ipiv, integer *info);
 
/* Subroutine */ extern "C" int chptri_(char *uplo, integer *n, complex *ap, integer *
	ipiv, complex *work, integer *info);
 
/* Subroutine */ extern "C" int chptrs_(char *uplo, integer *n, integer *nrhs, complex *
	ap, integer *ipiv, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int chsein_(char *side, char *eigsrc, char *initv, logical *
	select, integer *n, complex *h__, integer *ldh, complex *w, complex *
	vl, integer *ldvl, complex *vr, integer *ldvr, integer *mm, integer *
	m, complex *work, real *rwork, integer *ifaill, integer *ifailr, 
	integer *info);
 
/* Subroutine */ extern "C" int chseqr_(char *job, char *compz, integer *n, integer *ilo,
	 integer *ihi, complex *h__, integer *ldh, complex *w, complex *z__, 
	integer *ldz, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int clabrd_(integer *m, integer *n, integer *nb, complex *a, 
	integer *lda, real *d__, real *e, complex *tauq, complex *taup, 
	complex *x, integer *ldx, complex *y, integer *ldy);
 
/* Subroutine */ extern "C" int clacgv_(integer *n, complex *x, integer *incx);
 
/* Subroutine */ extern "C" int clacon_(integer *n, complex *v, complex *x, real *est, 
	integer *kase);
 
/* Subroutine */ extern "C" int clacp2_(char *uplo, integer *m, integer *n, real *a, 
	integer *lda, complex *b, integer *ldb);
 
/* Subroutine */ extern "C" int clacpy_(char *uplo, integer *m, integer *n, complex *a, 
	integer *lda, complex *b, integer *ldb);
 
/* Subroutine */ extern "C" int clacrm_(integer *m, integer *n, complex *a, integer *lda,
	 real *b, integer *ldb, complex *c__, integer *ldc, real *rwork);
 
/* Subroutine */ extern "C" int clacrt_(integer *n, complex *cx, integer *incx, complex *
	cy, integer *incy, complex *c__, complex *s);
 
/* Subroutine */ extern "C" int claed0_(integer *qsiz, integer *n, real *d__, real *e, 
	complex *q, integer *ldq, complex *qstore, integer *ldqs, real *rwork,
	 integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int claed7_(integer *n, integer *cutpnt, integer *qsiz, 
	integer *tlvls, integer *curlvl, integer *curpbm, real *d__, complex *
	q, integer *ldq, real *rho, integer *indxq, real *qstore, integer *
	qptr, integer *prmptr, integer *perm, integer *givptr, integer *
	givcol, real *givnum, complex *work, real *rwork, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int claed8_(integer *k, integer *n, integer *qsiz, complex *
	q, integer *ldq, real *d__, real *rho, integer *cutpnt, real *z__, 
	real *dlamda, complex *q2, integer *ldq2, real *w, integer *indxp, 
	integer *indx, integer *indxq, integer *perm, integer *givptr, 
	integer *givcol, real *givnum, integer *info);
 
/* Subroutine */ extern "C" int claein_(logical *rightv, logical *noinit, integer *n, 
	complex *h__, integer *ldh, complex *w, complex *v, complex *b, 
	integer *ldb, real *rwork, real *eps3, real *smlnum, integer *info);
 
/* Subroutine */ extern "C" int claesy_(complex *a, complex *b, complex *c__, complex *
	rt1, complex *rt2, complex *evscal, complex *cs1, complex *sn1);
 
/* Subroutine */ extern "C" int claev2_(complex *a, complex *b, complex *c__, real *rt1, 
	real *rt2, real *cs1, complex *sn1);
 
/* Subroutine */ extern "C" int clags2_(logical *upper, real *a1, complex *a2, real *a3, 
	real *b1, complex *b2, real *b3, real *csu, complex *snu, real *csv, 
	complex *snv, real *csq, complex *snq);
 
/* Subroutine */ extern "C" int clagtm_(char *trans, integer *n, integer *nrhs, real *
	alpha, complex *dl, complex *d__, complex *du, complex *x, integer *
	ldx, real *beta, complex *b, integer *ldb);
 
/* Subroutine */ extern "C" int clahef_(char *uplo, integer *n, integer *nb, integer *kb,
	 complex *a, integer *lda, integer *ipiv, complex *w, integer *ldw, 
	integer *info);
 
/* Subroutine */ extern "C" int clahqr_(logical *wantt, logical *wantz, integer *n, 
	integer *ilo, integer *ihi, complex *h__, integer *ldh, complex *w, 
	integer *iloz, integer *ihiz, complex *z__, integer *ldz, integer *
	info);
 
/* Subroutine */ extern "C" int clahrd_(integer *n, integer *k, integer *nb, complex *a, 
	integer *lda, complex *tau, complex *t, integer *ldt, complex *y, 
	integer *ldy);
 
/* Subroutine */ extern "C" int claic1_(integer *job, integer *j, complex *x, real *sest,
	 complex *w, complex *gamma, real *sestpr, complex *s, complex *c__);
 
/* Subroutine */ extern "C" int clals0_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, integer *nrhs, complex *b, integer *ldb, complex *bx, 
	integer *ldbx, integer *perm, integer *givptr, integer *givcol, 
	integer *ldgcol, real *givnum, integer *ldgnum, real *poles, real *
	difl, real *difr, real *z__, integer *k, real *c__, real *s, real *
	rwork, integer *info);
 
/* Subroutine */ extern "C" int clalsa_(integer *icompq, integer *smlsiz, integer *n, 
	integer *nrhs, complex *b, integer *ldb, complex *bx, integer *ldbx, 
	real *u, integer *ldu, real *vt, integer *k, real *difl, real *difr, 
	real *z__, real *poles, integer *givptr, integer *givcol, integer *
	ldgcol, integer *perm, real *givnum, real *c__, real *s, real *rwork, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int clapll_(integer *n, complex *x, integer *incx, complex *
	y, integer *incy, real *ssmin);
 
/* Subroutine */ extern "C" int clapmt_(logical *forwrd, integer *m, integer *n, complex 
	*x, integer *ldx, integer *k);
 
/* Subroutine */ extern "C" int claqgb_(integer *m, integer *n, integer *kl, integer *ku,
	 complex *ab, integer *ldab, real *r__, real *c__, real *rowcnd, real 
	*colcnd, real *amax, char *equed);
 
/* Subroutine */ extern "C" int claqge_(integer *m, integer *n, complex *a, integer *lda,
	 real *r__, real *c__, real *rowcnd, real *colcnd, real *amax, char *
	equed);
 
/* Subroutine */ extern "C" int claqhb_(char *uplo, integer *n, integer *kd, complex *ab,
	 integer *ldab, real *s, real *scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int claqhe_(char *uplo, integer *n, complex *a, integer *lda,
	 real *s, real *scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int claqhp_(char *uplo, integer *n, complex *ap, real *s, 
	real *scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int claqp2_(integer *m, integer *n, integer *offset, complex 
	*a, integer *lda, integer *jpvt, complex *tau, real *vn1, real *vn2, 
	complex *work);
 
/* Subroutine */ extern "C" int claqps_(integer *m, integer *n, integer *offset, integer 
	*nb, integer *kb, complex *a, integer *lda, integer *jpvt, complex *
	tau, real *vn1, real *vn2, complex *auxv, complex *f, integer *ldf);
 
/* Subroutine */ extern "C" int claqsb_(char *uplo, integer *n, integer *kd, complex *ab,
	 integer *ldab, real *s, real *scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int claqsp_(char *uplo, integer *n, complex *ap, real *s, 
	real *scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int claqsy_(char *uplo, integer *n, complex *a, integer *lda,
	 real *s, real *scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int clar1v_(integer *n, integer *b1, integer *bn, real *
	sigma, real *d__, real *l, real *ld, real *lld, real *gersch, complex 
	*z__, real *ztz, real *mingma, integer *r__, integer *isuppz, real *
	work);
 
/* Subroutine */ extern "C" int clar2v_(integer *n, complex *x, complex *y, complex *z__,
	 integer *incx, real *c__, complex *s, integer *incc);
 
/* Subroutine */ extern "C" int clarcm_(integer *m, integer *n, real *a, integer *lda, 
	complex *b, integer *ldb, complex *c__, integer *ldc, real *rwork);
 
/* Subroutine */ extern "C" int clarf_(char *side, integer *m, integer *n, complex *v, 
	integer *incv, complex *tau, complex *c__, integer *ldc, complex *
	work);
 
/* Subroutine */ extern "C" int clarfb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, complex *v, integer *ldv, 
	complex *t, integer *ldt, complex *c__, integer *ldc, complex *work, 
	integer *ldwork);
 
/* Subroutine */ extern "C" int clarfg_(integer *n, complex *alpha, complex *x, integer *
	incx, complex *tau);
 
/* Subroutine */ extern "C" int clarft_(char *direct, char *storev, integer *n, integer *
	k, complex *v, integer *ldv, complex *tau, complex *t, integer *ldt);
 
/* Subroutine */ extern "C" int clarfx_(char *side, integer *m, integer *n, complex *v, 
	complex *tau, complex *c__, integer *ldc, complex *work);
 
/* Subroutine */ extern "C" int clargv_(integer *n, complex *x, integer *incx, complex *
	y, integer *incy, real *c__, integer *incc);
 
/* Subroutine */ extern "C" int clarnv_(integer *idist, integer *iseed, integer *n, 
	complex *x);
 
/* Subroutine */ extern "C" int clarrv_(integer *n, real *d__, real *l, integer *isplit, 
	integer *m, real *w, integer *iblock, real *gersch, real *tol, 
	complex *z__, integer *ldz, integer *isuppz, real *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int clartg_(complex *f, complex *g, real *cs, complex *sn, 
	complex *r__);
 
/* Subroutine */ extern "C" int clartv_(integer *n, complex *x, integer *incx, complex *
	y, integer *incy, real *c__, complex *s, integer *incc);
 
/* Subroutine */ extern "C" int clarz_(char *side, integer *m, integer *n, integer *l, 
	complex *v, integer *incv, complex *tau, complex *c__, integer *ldc, 
	complex *work);
 
/* Subroutine */ extern "C" int clarzb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, integer *l, complex *v, 
	integer *ldv, complex *t, integer *ldt, complex *c__, integer *ldc, 
	complex *work, integer *ldwork);
 
/* Subroutine */ extern "C" int clarzt_(char *direct, char *storev, integer *n, integer *
	k, complex *v, integer *ldv, complex *tau, complex *t, integer *ldt);
 
/* Subroutine */ extern "C" int clascl_(char *type__, integer *kl, integer *ku, real *
	cfrom, real *cto, integer *m, integer *n, complex *a, integer *lda, 
	integer *info);
 
/* Subroutine */ extern "C" int claset_(char *uplo, integer *m, integer *n, complex *
	alpha, complex *beta, complex *a, integer *lda);
 
/* Subroutine */ extern "C" int clasr_(char *side, char *pivot, char *direct, integer *m,
	 integer *n, real *c__, real *s, complex *a, integer *lda);
 
/* Subroutine */ extern "C" int classq_(integer *n, complex *x, integer *incx, real *
	scale, real *sumsq);
 
/* Subroutine */ extern "C" int claswp_(integer *n, complex *a, integer *lda, integer *
	k1, integer *k2, integer *ipiv, integer *incx);
 
/* Subroutine */ extern "C" int clasyf_(char *uplo, integer *n, integer *nb, integer *kb,
	 complex *a, integer *lda, integer *ipiv, complex *w, integer *ldw, 
	integer *info);
 
/* Subroutine */ extern "C" int clatbs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, integer *kd, complex *ab, integer *ldab, complex *
	x, real *scale, real *cnorm, integer *info);
 
/* Subroutine */ extern "C" int clatdf_(integer *ijob, integer *n, complex *z__, integer 
	*ldz, complex *rhs, real *rdsum, real *rdscal, integer *ipiv, integer 
	*jpiv);
 
/* Subroutine */ extern "C" int clatps_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, complex *ap, complex *x, real *scale, real *cnorm,
	 integer *info);
 
/* Subroutine */ extern "C" int clatrd_(char *uplo, integer *n, integer *nb, complex *a, 
	integer *lda, real *e, complex *tau, complex *w, integer *ldw);
 
/* Subroutine */ extern "C" int clatrs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, complex *a, integer *lda, complex *x, real *scale,
	 real *cnorm, integer *info);
 
/* Subroutine */ extern "C" int clatrz_(integer *m, integer *n, integer *l, complex *a, 
	integer *lda, complex *tau, complex *work);
 
/* Subroutine */ extern "C" int clatzm_(char *side, integer *m, integer *n, complex *v, 
	integer *incv, complex *tau, complex *c1, complex *c2, integer *ldc, 
	complex *work);
 
/* Subroutine */ extern "C" int clauu2_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *info);
 
/* Subroutine */ extern "C" int clauum_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *info);
 
/* Subroutine */ extern "C" int cpbcon_(char *uplo, integer *n, integer *kd, complex *ab,
	 integer *ldab, real *anorm, real *rcond, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int cpbequ_(char *uplo, integer *n, integer *kd, complex *ab,
	 integer *ldab, real *s, real *scond, real *amax, integer *info);
 
/* Subroutine */ extern "C" int cpbrfs_(char *uplo, integer *n, integer *kd, integer *
	nrhs, complex *ab, integer *ldab, complex *afb, integer *ldafb, 
	complex *b, integer *ldb, complex *x, integer *ldx, real *ferr, real *
	berr, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cpbstf_(char *uplo, integer *n, integer *kd, complex *ab,
	 integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int cpbsv_(char *uplo, integer *n, integer *kd, integer *
	nrhs, complex *ab, integer *ldab, complex *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int cpbsvx_(char *fact, char *uplo, integer *n, integer *kd, 
	integer *nrhs, complex *ab, integer *ldab, complex *afb, integer *
	ldafb, char *equed, real *s, complex *b, integer *ldb, complex *x, 
	integer *ldx, real *rcond, real *ferr, real *berr, complex *work, 
	real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cpbtf2_(char *uplo, integer *n, integer *kd, complex *ab,
	 integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int cpbtrf_(char *uplo, integer *n, integer *kd, complex *ab,
	 integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int cpbtrs_(char *uplo, integer *n, integer *kd, integer *
	nrhs, complex *ab, integer *ldab, complex *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int cpocon_(char *uplo, integer *n, complex *a, integer *lda,
	 real *anorm, real *rcond, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cpoequ_(integer *n, complex *a, integer *lda, real *s, 
	real *scond, real *amax, integer *info);
 
/* Subroutine */ extern "C" int cporfs_(char *uplo, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *af, integer *ldaf, complex *b, integer *ldb,
	 complex *x, integer *ldx, real *ferr, real *berr, complex *work, 
	real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cposv_(char *uplo, integer *n, integer *nrhs, complex *a,
	 integer *lda, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cposvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, char *
	equed, real *s, complex *b, integer *ldb, complex *x, integer *ldx, 
	real *rcond, real *ferr, real *berr, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int cpotf2_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *info);
 
/* Subroutine */ extern "C" int cpotrf_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *info);
 
/* Subroutine */ extern "C" int cpotri_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *info);
 
/* Subroutine */ extern "C" int cpotrs_(char *uplo, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cppcon_(char *uplo, integer *n, complex *ap, real *anorm,
	 real *rcond, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cppequ_(char *uplo, integer *n, complex *ap, real *s, 
	real *scond, real *amax, integer *info);
 
/* Subroutine */ extern "C" int cpprfs_(char *uplo, integer *n, integer *nrhs, complex *
	ap, complex *afp, complex *b, integer *ldb, complex *x, integer *ldx, 
	real *ferr, real *berr, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cppsv_(char *uplo, integer *n, integer *nrhs, complex *
	ap, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cppsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *ap, complex *afp, char *equed, real *s, complex *b, 
	integer *ldb, complex *x, integer *ldx, real *rcond, real *ferr, real 
	*berr, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cpptrf_(char *uplo, integer *n, complex *ap, integer *
	info);
 
/* Subroutine */ extern "C" int cpptri_(char *uplo, integer *n, complex *ap, integer *
	info);
 
/* Subroutine */ extern "C" int cpptrs_(char *uplo, integer *n, integer *nrhs, complex *
	ap, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cptcon_(integer *n, real *d__, complex *e, real *anorm, 
	real *rcond, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cptrfs_(char *uplo, integer *n, integer *nrhs, real *d__,
	 complex *e, real *df, complex *ef, complex *b, integer *ldb, complex 
	*x, integer *ldx, real *ferr, real *berr, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int cptsv_(integer *n, integer *nrhs, real *d__, complex *e, 
	complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cptsvx_(char *fact, integer *n, integer *nrhs, real *d__,
	 complex *e, real *df, complex *ef, complex *b, integer *ldb, complex 
	*x, integer *ldx, real *rcond, real *ferr, real *berr, complex *work, 
	real *rwork, integer *info);
 
/* Subroutine */ extern "C" int cpttrf_(integer *n, real *d__, complex *e, integer *info);
 
/* Subroutine */ extern "C" int cpttrs_(char *uplo, integer *n, integer *nrhs, real *d__,
	 complex *e, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cptts2_(integer *iuplo, integer *n, integer *nrhs, real *
	d__, complex *e, complex *b, integer *ldb);
 
/* Subroutine */ extern "C" int crot_(integer *n, complex *cx, integer *incx, complex *
	cy, integer *incy, real *c__, complex *s);
 
/* Subroutine */ extern "C" int cspcon_(char *uplo, integer *n, complex *ap, integer *
	ipiv, real *anorm, real *rcond, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cspmv_(char *uplo, integer *n, complex *alpha, complex *
	ap, complex *x, integer *incx, complex *beta, complex *y, integer *
	incy);
 
/* Subroutine */ extern "C" int cspr_(char *uplo, integer *n, complex *alpha, complex *x,
	 integer *incx, complex *ap);
 
/* Subroutine */ extern "C" int csprfs_(char *uplo, integer *n, integer *nrhs, complex *
	ap, complex *afp, integer *ipiv, complex *b, integer *ldb, complex *x,
	 integer *ldx, real *ferr, real *berr, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int cspsv_(char *uplo, integer *n, integer *nrhs, complex *
	ap, integer *ipiv, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int cspsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *ap, complex *afp, integer *ipiv, complex *b, integer *
	ldb, complex *x, integer *ldx, real *rcond, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int csptrf_(char *uplo, integer *n, complex *ap, integer *
	ipiv, integer *info);
 
/* Subroutine */ extern "C" int csptri_(char *uplo, integer *n, complex *ap, integer *
	ipiv, complex *work, integer *info);
 
/* Subroutine */ extern "C" int csptrs_(char *uplo, integer *n, integer *nrhs, complex *
	ap, integer *ipiv, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int csrot_(integer *n, complex *cx, integer *incx, complex *
	cy, integer *incy, real *c__, real *s);
 
/* Subroutine */ extern "C" int csrscl_(integer *n, real *sa, complex *sx, integer *incx);
 
/* Subroutine */ extern "C" int cstedc_(char *compz, integer *n, real *d__, real *e, 
	complex *z__, integer *ldz, complex *work, integer *lwork, real *
	rwork, integer *lrwork, integer *iwork, integer *liwork, integer *
	info);
 
/* Subroutine */ extern "C" int cstein_(integer *n, real *d__, real *e, integer *m, real 
	*w, integer *iblock, integer *isplit, complex *z__, integer *ldz, 
	real *work, integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int csteqr_(char *compz, integer *n, real *d__, real *e, 
	complex *z__, integer *ldz, real *work, integer *info);
 
/* Subroutine */ extern "C" int csycon_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *ipiv, real *anorm, real *rcond, complex *work, integer *
	info);
 
/* Subroutine */ extern "C" int csymv_(char *uplo, integer *n, complex *alpha, complex *
	a, integer *lda, complex *x, integer *incx, complex *beta, complex *y,
	 integer *incy);
 
/* Subroutine */ extern "C" int csyr_(char *uplo, integer *n, complex *alpha, complex *x,
	 integer *incx, complex *a, integer *lda);
 
/* Subroutine */ extern "C" int csyrfs_(char *uplo, integer *n, integer *nrhs, complex *
	a, integer *lda, complex *af, integer *ldaf, integer *ipiv, complex *
	b, integer *ldb, complex *x, integer *ldx, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int csysv_(char *uplo, integer *n, integer *nrhs, complex *a,
	 integer *lda, integer *ipiv, complex *b, integer *ldb, complex *work,
	 integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int csysvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, complex *a, integer *lda, complex *af, integer *ldaf, integer *
	ipiv, complex *b, integer *ldb, complex *x, integer *ldx, real *rcond,
	 real *ferr, real *berr, complex *work, integer *lwork, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int csytf2_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int csytrf_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *ipiv, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int csytri_(char *uplo, integer *n, complex *a, integer *lda,
	 integer *ipiv, complex *work, integer *info);
 
/* Subroutine */ extern "C" int csytrs_(char *uplo, integer *n, integer *nrhs, complex *
	a, integer *lda, integer *ipiv, complex *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int ctbcon_(char *norm, char *uplo, char *diag, integer *n, 
	integer *kd, complex *ab, integer *ldab, real *rcond, complex *work, 
	real *rwork, integer *info);
 
/* Subroutine */ extern "C" int ctbrfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *kd, integer *nrhs, complex *ab, integer *ldab, complex *b, 
	integer *ldb, complex *x, integer *ldx, real *ferr, real *berr, 
	complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int ctbtrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *kd, integer *nrhs, complex *ab, integer *ldab, complex *b, 
	integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int ctgevc_(char *side, char *howmny, logical *select, 
	integer *n, complex *a, integer *lda, complex *b, integer *ldb, 
	complex *vl, integer *ldvl, complex *vr, integer *ldvr, integer *mm, 
	integer *m, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int ctgex2_(logical *wantq, logical *wantz, integer *n, 
	complex *a, integer *lda, complex *b, integer *ldb, complex *q, 
	integer *ldq, complex *z__, integer *ldz, integer *j1, integer *info);
 
/* Subroutine */ extern "C" int ctgexc_(logical *wantq, logical *wantz, integer *n, 
	complex *a, integer *lda, complex *b, integer *ldb, complex *q, 
	integer *ldq, complex *z__, integer *ldz, integer *ifst, integer *
	ilst, integer *info);
 
/* Subroutine */ extern "C" int ctgsen_(integer *ijob, logical *wantq, logical *wantz, 
	logical *select, integer *n, complex *a, integer *lda, complex *b, 
	integer *ldb, complex *alpha, complex *beta, complex *q, integer *ldq,
	 complex *z__, integer *ldz, integer *m, real *pl, real *pr, real *
	dif, complex *work, integer *lwork, integer *iwork, integer *liwork, 
	integer *info);
 
/* Subroutine */ extern "C" int ctgsja_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, integer *k, integer *l, complex *a, integer *
	lda, complex *b, integer *ldb, real *tola, real *tolb, real *alpha, 
	real *beta, complex *u, integer *ldu, complex *v, integer *ldv, 
	complex *q, integer *ldq, complex *work, integer *ncycle, integer *
	info);
 
/* Subroutine */ extern "C" int ctgsna_(char *job, char *howmny, logical *select, 
	integer *n, complex *a, integer *lda, complex *b, integer *ldb, 
	complex *vl, integer *ldvl, complex *vr, integer *ldvr, real *s, real 
	*dif, integer *mm, integer *m, complex *work, integer *lwork, integer 
	*iwork, integer *info);
 
/* Subroutine */ extern "C" int ctgsy2_(char *trans, integer *ijob, integer *m, integer *
	n, complex *a, integer *lda, complex *b, integer *ldb, complex *c__, 
	integer *ldc, complex *d__, integer *ldd, complex *e, integer *lde, 
	complex *f, integer *ldf, real *scale, real *rdsum, real *rdscal, 
	integer *info);
 
/* Subroutine */ extern "C" int ctgsyl_(char *trans, integer *ijob, integer *m, integer *
	n, complex *a, integer *lda, complex *b, integer *ldb, complex *c__, 
	integer *ldc, complex *d__, integer *ldd, complex *e, integer *lde, 
	complex *f, integer *ldf, real *scale, real *dif, complex *work, 
	integer *lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int ctpcon_(char *norm, char *uplo, char *diag, integer *n, 
	complex *ap, real *rcond, complex *work, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int ctprfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, complex *ap, complex *b, integer *ldb, complex *x, 
	integer *ldx, real *ferr, real *berr, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int ctptri_(char *uplo, char *diag, integer *n, complex *ap, 
	integer *info);
 
/* Subroutine */ extern "C" int ctptrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, complex *ap, complex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int ctrcon_(char *norm, char *uplo, char *diag, integer *n, 
	complex *a, integer *lda, real *rcond, complex *work, real *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int ctrevc_(char *side, char *howmny, logical *select, 
	integer *n, complex *t, integer *ldt, complex *vl, integer *ldvl, 
	complex *vr, integer *ldvr, integer *mm, integer *m, complex *work, 
	real *rwork, integer *info);
 
/* Subroutine */ extern "C" int ctrexc_(char *compq, integer *n, complex *t, integer *
	ldt, complex *q, integer *ldq, integer *ifst, integer *ilst, integer *
	info);
 
/* Subroutine */ extern "C" int ctrrfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, complex *a, integer *lda, complex *b, integer *ldb, 
	complex *x, integer *ldx, real *ferr, real *berr, complex *work, real 
	*rwork, integer *info);
 
/* Subroutine */ extern "C" int ctrsen_(char *job, char *compq, logical *select, integer 
	*n, complex *t, integer *ldt, complex *q, integer *ldq, complex *w, 
	integer *m, real *s, real *sep, complex *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int ctrsna_(char *job, char *howmny, logical *select, 
	integer *n, complex *t, integer *ldt, complex *vl, integer *ldvl, 
	complex *vr, integer *ldvr, real *s, real *sep, integer *mm, integer *
	m, complex *work, integer *ldwork, real *rwork, integer *info);
 
/* Subroutine */ extern "C" int ctrsyl_(char *trana, char *tranb, integer *isgn, integer 
	*m, integer *n, complex *a, integer *lda, complex *b, integer *ldb, 
	complex *c__, integer *ldc, real *scale, integer *info);
 
/* Subroutine */ extern "C" int ctrti2_(char *uplo, char *diag, integer *n, complex *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int ctrtri_(char *uplo, char *diag, integer *n, complex *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int ctrtrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, complex *a, integer *lda, complex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int ctzrqf_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, integer *info);
 
/* Subroutine */ extern "C" int ctzrzf_(integer *m, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cung2l_(integer *m, integer *n, integer *k, complex *a, 
	integer *lda, complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cung2r_(integer *m, integer *n, integer *k, complex *a, 
	integer *lda, complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cungbr_(char *vect, integer *m, integer *n, integer *k, 
	complex *a, integer *lda, complex *tau, complex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int cunghr_(integer *n, integer *ilo, integer *ihi, complex *
	a, integer *lda, complex *tau, complex *work, integer *lwork, integer 
	*info);
 
/* Subroutine */ extern "C" int cungl2_(integer *m, integer *n, integer *k, complex *a, 
	integer *lda, complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cunglq_(integer *m, integer *n, integer *k, complex *a, 
	integer *lda, complex *tau, complex *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int cungql_(integer *m, integer *n, integer *k, complex *a, 
	integer *lda, complex *tau, complex *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int cungqr_(integer *m, integer *n, integer *k, complex *a, 
	integer *lda, complex *tau, complex *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int cungr2_(integer *m, integer *n, integer *k, complex *a, 
	integer *lda, complex *tau, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cungrq_(integer *m, integer *n, integer *k, complex *a, 
	integer *lda, complex *tau, complex *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int cungtr_(char *uplo, integer *n, complex *a, integer *lda,
	 complex *tau, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cunm2l_(char *side, char *trans, integer *m, integer *n, 
	integer *k, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cunm2r_(char *side, char *trans, integer *m, integer *n, 
	integer *k, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cunmbr_(char *vect, char *side, char *trans, integer *m, 
	integer *n, integer *k, complex *a, integer *lda, complex *tau, 
	complex *c__, integer *ldc, complex *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int cunmhr_(char *side, char *trans, integer *m, integer *n, 
	integer *ilo, integer *ihi, complex *a, integer *lda, complex *tau, 
	complex *c__, integer *ldc, complex *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int cunml2_(char *side, char *trans, integer *m, integer *n, 
	integer *k, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cunmlq_(char *side, char *trans, integer *m, integer *n, 
	integer *k, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cunmql_(char *side, char *trans, integer *m, integer *n, 
	integer *k, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cunmqr_(char *side, char *trans, integer *m, integer *n, 
	integer *k, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cunmr2_(char *side, char *trans, integer *m, integer *n, 
	integer *k, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cunmr3_(char *side, char *trans, integer *m, integer *n, 
	integer *k, integer *l, complex *a, integer *lda, complex *tau, 
	complex *c__, integer *ldc, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cunmrq_(char *side, char *trans, integer *m, integer *n, 
	integer *k, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cunmrz_(char *side, char *trans, integer *m, integer *n, 
	integer *k, integer *l, complex *a, integer *lda, complex *tau, 
	complex *c__, integer *ldc, complex *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int cunmtr_(char *side, char *uplo, char *trans, integer *m, 
	integer *n, complex *a, integer *lda, complex *tau, complex *c__, 
	integer *ldc, complex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int cupgtr_(char *uplo, integer *n, complex *ap, complex *
	tau, complex *q, integer *ldq, complex *work, integer *info);
 
/* Subroutine */ extern "C" int cupmtr_(char *side, char *uplo, char *trans, integer *m, 
	integer *n, complex *ap, complex *tau, complex *c__, integer *ldc, 
	complex *work, integer *info);
 
/* Subroutine */ extern "C" int dbdsdc_(char *uplo, char *compq, integer *n, doublereal *
	d__, doublereal *e, doublereal *u, integer *ldu, doublereal *vt, 
	integer *ldvt, doublereal *q, integer *iq, doublereal *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dbdsqr_(char *uplo, integer *n, integer *ncvt, integer *
	nru, integer *ncc, doublereal *d__, doublereal *e, doublereal *vt, 
	integer *ldvt, doublereal *u, integer *ldu, doublereal *c__, integer *
	ldc, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int ddisna_(char *job, integer *m, integer *n, doublereal *
	d__, doublereal *sep, integer *info);
 
/* Subroutine */ extern "C" int dgbbrd_(char *vect, integer *m, integer *n, integer *ncc,
	 integer *kl, integer *ku, doublereal *ab, integer *ldab, doublereal *
	d__, doublereal *e, doublereal *q, integer *ldq, doublereal *pt, 
	integer *ldpt, doublereal *c__, integer *ldc, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int dgbcon_(char *norm, integer *n, integer *kl, integer *ku,
	 doublereal *ab, integer *ldab, integer *ipiv, doublereal *anorm, 
	doublereal *rcond, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dgbequ_(integer *m, integer *n, integer *kl, integer *ku,
	 doublereal *ab, integer *ldab, doublereal *r__, doublereal *c__, 
	doublereal *rowcnd, doublereal *colcnd, doublereal *amax, integer *
	info);
 
/* Subroutine */ extern "C" int dgbrfs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, doublereal *ab, integer *ldab, doublereal *afb, 
	integer *ldafb, integer *ipiv, doublereal *b, integer *ldb, 
	doublereal *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dgbsv_(integer *n, integer *kl, integer *ku, integer *
	nrhs, doublereal *ab, integer *ldab, integer *ipiv, doublereal *b, 
	integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dgbsvx_(char *fact, char *trans, integer *n, integer *kl,
	 integer *ku, integer *nrhs, doublereal *ab, integer *ldab, 
	doublereal *afb, integer *ldafb, integer *ipiv, char *equed, 
	doublereal *r__, doublereal *c__, doublereal *b, integer *ldb, 
	doublereal *x, integer *ldx, doublereal *rcond, doublereal *ferr, 
	doublereal *berr, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dgbtf2_(integer *m, integer *n, integer *kl, integer *ku,
	 doublereal *ab, integer *ldab, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int dgbtrf_(integer *m, integer *n, integer *kl, integer *ku,
	 doublereal *ab, integer *ldab, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int dgbtrs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, doublereal *ab, integer *ldab, integer *ipiv, 
	doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dgebak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, doublereal *scale, integer *m, doublereal *v, integer *
	ldv, integer *info);
 
/* Subroutine */ extern "C" int dgebal_(char *job, integer *n, doublereal *a, integer *
	lda, integer *ilo, integer *ihi, doublereal *scale, integer *info);
 
/* Subroutine */ extern "C" int dgebd2_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *d__, doublereal *e, doublereal *tauq, doublereal *
	taup, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dgebrd_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *d__, doublereal *e, doublereal *tauq, doublereal *
	taup, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgecon_(char *norm, integer *n, doublereal *a, integer *
	lda, doublereal *anorm, doublereal *rcond, doublereal *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dgeequ_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *r__, doublereal *c__, doublereal *rowcnd, doublereal 
	*colcnd, doublereal *amax, integer *info);
 
/* Subroutine */ extern "C" int dgees_(char *jobvs, char *sort, L_fp select, integer *n, 
	doublereal *a, integer *lda, integer *sdim, doublereal *wr, 
	doublereal *wi, doublereal *vs, integer *ldvs, doublereal *work, 
	integer *lwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int dgeesx_(char *jobvs, char *sort, L_fp select, char *
	sense, integer *n, doublereal *a, integer *lda, integer *sdim, 
	doublereal *wr, doublereal *wi, doublereal *vs, integer *ldvs, 
	doublereal *rconde, doublereal *rcondv, doublereal *work, integer *
	lwork, integer *iwork, integer *liwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int dgeev_(char *jobvl, char *jobvr, integer *n, doublereal *
	a, integer *lda, doublereal *wr, doublereal *wi, doublereal *vl, 
	integer *ldvl, doublereal *vr, integer *ldvr, doublereal *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgeevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, doublereal *a, integer *lda, doublereal *wr, 
	doublereal *wi, doublereal *vl, integer *ldvl, doublereal *vr, 
	integer *ldvr, integer *ilo, integer *ihi, doublereal *scale, 
	doublereal *abnrm, doublereal *rconde, doublereal *rcondv, doublereal 
	*work, integer *lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dgegs_(char *jobvsl, char *jobvsr, integer *n, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *
	alphar, doublereal *alphai, doublereal *beta, doublereal *vsl, 
	integer *ldvsl, doublereal *vsr, integer *ldvsr, doublereal *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgegv_(char *jobvl, char *jobvr, integer *n, doublereal *
	a, integer *lda, doublereal *b, integer *ldb, doublereal *alphar, 
	doublereal *alphai, doublereal *beta, doublereal *vl, integer *ldvl, 
	doublereal *vr, integer *ldvr, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dgehd2_(integer *n, integer *ilo, integer *ihi, 
	doublereal *a, integer *lda, doublereal *tau, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int dgehrd_(integer *n, integer *ilo, integer *ihi, 
	doublereal *a, integer *lda, doublereal *tau, doublereal *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgelq2_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dgelqf_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgels_(char *trans, integer *m, integer *n, integer *
	nrhs, doublereal *a, integer *lda, doublereal *b, integer *ldb, 
	doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgelsd_(integer *m, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *
	s, doublereal *rcond, integer *rank, doublereal *work, integer *lwork,
	 integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dgelss_(integer *m, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *
	s, doublereal *rcond, integer *rank, doublereal *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int dgelsx_(integer *m, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, integer *
	jpvt, doublereal *rcond, integer *rank, doublereal *work, integer *
	info);
 
/* Subroutine */ extern "C" int dgelsy_(integer *m, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, integer *
	jpvt, doublereal *rcond, integer *rank, doublereal *work, integer *
	lwork, integer *info);
 
/* Subroutine */ extern "C" int dgeql2_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dgeqlf_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgeqp3_(integer *m, integer *n, doublereal *a, integer *
	lda, integer *jpvt, doublereal *tau, doublereal *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int dgeqpf_(integer *m, integer *n, doublereal *a, integer *
	lda, integer *jpvt, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dgeqr2_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dgeqrf_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgerfs_(char *trans, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, doublereal *af, integer *ldaf, integer *
	ipiv, doublereal *b, integer *ldb, doublereal *x, integer *ldx, 
	doublereal *ferr, doublereal *berr, doublereal *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dgerq2_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dgerqf_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgesc2_(integer *n, doublereal *a, integer *lda, 
	doublereal *rhs, integer *ipiv, integer *jpiv, doublereal *scale);
 
/* Subroutine */ extern "C" int dgesdd_(char *jobz, integer *m, integer *n, doublereal *
	a, integer *lda, doublereal *s, doublereal *u, integer *ldu, 
	doublereal *vt, integer *ldvt, doublereal *work, integer *lwork, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dgesv_(integer *n, integer *nrhs, doublereal *a, integer 
	*lda, integer *ipiv, doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dgesvd_(char *jobu, char *jobvt, integer *m, integer *n, 
	doublereal *a, integer *lda, doublereal *s, doublereal *u, integer *
	ldu, doublereal *vt, integer *ldvt, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dgesvx_(char *fact, char *trans, integer *n, integer *
	nrhs, doublereal *a, integer *lda, doublereal *af, integer *ldaf, 
	integer *ipiv, char *equed, doublereal *r__, doublereal *c__, 
	doublereal *b, integer *ldb, doublereal *x, integer *ldx, doublereal *
	rcond, doublereal *ferr, doublereal *berr, doublereal *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dgetc2_(integer *n, doublereal *a, integer *lda, integer 
	*ipiv, integer *jpiv, integer *info);
 
/* Subroutine */ extern "C" int dgetf2_(integer *m, integer *n, doublereal *a, integer *
	lda, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int dgetrf_(integer *m, integer *n, doublereal *a, integer *
	lda, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int dgetri_(integer *n, doublereal *a, integer *lda, integer 
	*ipiv, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dgetrs_(char *trans, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, integer *ipiv, doublereal *b, integer *
	ldb, integer *info);
 
/* Subroutine */ extern "C" int dggbak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, doublereal *lscale, doublereal *rscale, integer *m, 
	doublereal *v, integer *ldv, integer *info);
 
/* Subroutine */ extern "C" int dggbal_(char *job, integer *n, doublereal *a, integer *
	lda, doublereal *b, integer *ldb, integer *ilo, integer *ihi, 
	doublereal *lscale, doublereal *rscale, doublereal *work, integer *
	info);
 
/* Subroutine */ extern "C" int dgges_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	delctg, integer *n, doublereal *a, integer *lda, doublereal *b, 
	integer *ldb, integer *sdim, doublereal *alphar, doublereal *alphai, 
	doublereal *beta, doublereal *vsl, integer *ldvsl, doublereal *vsr, 
	integer *ldvsr, doublereal *work, integer *lwork, logical *bwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dggesx_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	delctg, char *sense, integer *n, doublereal *a, integer *lda, 
	doublereal *b, integer *ldb, integer *sdim, doublereal *alphar, 
	doublereal *alphai, doublereal *beta, doublereal *vsl, integer *ldvsl,
	 doublereal *vsr, integer *ldvsr, doublereal *rconde, doublereal *
	rcondv, doublereal *work, integer *lwork, integer *iwork, integer *
	liwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int dggev_(char *jobvl, char *jobvr, integer *n, doublereal *
	a, integer *lda, doublereal *b, integer *ldb, doublereal *alphar, 
	doublereal *alphai, doublereal *beta, doublereal *vl, integer *ldvl, 
	doublereal *vr, integer *ldvr, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dggevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, doublereal *a, integer *lda, doublereal *b, 
	integer *ldb, doublereal *alphar, doublereal *alphai, doublereal *
	beta, doublereal *vl, integer *ldvl, doublereal *vr, integer *ldvr, 
	integer *ilo, integer *ihi, doublereal *lscale, doublereal *rscale, 
	doublereal *abnrm, doublereal *bbnrm, doublereal *rconde, doublereal *
	rcondv, doublereal *work, integer *lwork, integer *iwork, logical *
	bwork, integer *info);
 
/* Subroutine */ extern "C" int dggglm_(integer *n, integer *m, integer *p, doublereal *
	a, integer *lda, doublereal *b, integer *ldb, doublereal *d__, 
	doublereal *x, doublereal *y, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dgghrd_(char *compq, char *compz, integer *n, integer *
	ilo, integer *ihi, doublereal *a, integer *lda, doublereal *b, 
	integer *ldb, doublereal *q, integer *ldq, doublereal *z__, integer *
	ldz, integer *info);
 
/* Subroutine */ extern "C" int dgglse_(integer *m, integer *n, integer *p, doublereal *
	a, integer *lda, doublereal *b, integer *ldb, doublereal *c__, 
	doublereal *d__, doublereal *x, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dggqrf_(integer *n, integer *m, integer *p, doublereal *
	a, integer *lda, doublereal *taua, doublereal *b, integer *ldb, 
	doublereal *taub, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dggrqf_(integer *m, integer *p, integer *n, doublereal *
	a, integer *lda, doublereal *taua, doublereal *b, integer *ldb, 
	doublereal *taub, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dggsvd_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *n, integer *p, integer *k, integer *l, doublereal *a, 
	integer *lda, doublereal *b, integer *ldb, doublereal *alpha, 
	doublereal *beta, doublereal *u, integer *ldu, doublereal *v, integer 
	*ldv, doublereal *q, integer *ldq, doublereal *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dggsvp_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, doublereal *a, integer *lda, doublereal *b, 
	integer *ldb, doublereal *tola, doublereal *tolb, integer *k, integer 
	*l, doublereal *u, integer *ldu, doublereal *v, integer *ldv, 
	doublereal *q, integer *ldq, integer *iwork, doublereal *tau, 
	doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dgtcon_(char *norm, integer *n, doublereal *dl, 
	doublereal *d__, doublereal *du, doublereal *du2, integer *ipiv, 
	doublereal *anorm, doublereal *rcond, doublereal *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dgtrfs_(char *trans, integer *n, integer *nrhs, 
	doublereal *dl, doublereal *d__, doublereal *du, doublereal *dlf, 
	doublereal *df, doublereal *duf, doublereal *du2, integer *ipiv, 
	doublereal *b, integer *ldb, doublereal *x, integer *ldx, doublereal *
	ferr, doublereal *berr, doublereal *work, integer *iwork, integer *
	info);
 
/* Subroutine */ extern "C" int dgtsv_(integer *n, integer *nrhs, doublereal *dl, 
	doublereal *d__, doublereal *du, doublereal *b, integer *ldb, integer 
	*info);
 
/* Subroutine */ extern "C" int dgtsvx_(char *fact, char *trans, integer *n, integer *
	nrhs, doublereal *dl, doublereal *d__, doublereal *du, doublereal *
	dlf, doublereal *df, doublereal *duf, doublereal *du2, integer *ipiv, 
	doublereal *b, integer *ldb, doublereal *x, integer *ldx, doublereal *
	rcond, doublereal *ferr, doublereal *berr, doublereal *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dgttrf_(integer *n, doublereal *dl, doublereal *d__, 
	doublereal *du, doublereal *du2, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int dgttrs_(char *trans, integer *n, integer *nrhs, 
	doublereal *dl, doublereal *d__, doublereal *du, doublereal *du2, 
	integer *ipiv, doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dgtts2_(integer *itrans, integer *n, integer *nrhs, 
	doublereal *dl, doublereal *d__, doublereal *du, doublereal *du2, 
	integer *ipiv, doublereal *b, integer *ldb);
 
/* Subroutine */ extern "C" int dhgeqz_(char *job, char *compq, char *compz, integer *n, 
	integer *ilo, integer *ihi, doublereal *a, integer *lda, doublereal *
	b, integer *ldb, doublereal *alphar, doublereal *alphai, doublereal *
	beta, doublereal *q, integer *ldq, doublereal *z__, integer *ldz, 
	doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dhsein_(char *side, char *eigsrc, char *initv, logical *
	select, integer *n, doublereal *h__, integer *ldh, doublereal *wr, 
	doublereal *wi, doublereal *vl, integer *ldvl, doublereal *vr, 
	integer *ldvr, integer *mm, integer *m, doublereal *work, integer *
	ifaill, integer *ifailr, integer *info);
 
/* Subroutine */ extern "C" int dhseqr_(char *job, char *compz, integer *n, integer *ilo,
	 integer *ihi, doublereal *h__, integer *ldh, doublereal *wr, 
	doublereal *wi, doublereal *z__, integer *ldz, doublereal *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dlabad_(doublereal *small, doublereal *large);
 
/* Subroutine */ extern "C" int dlabrd_(integer *m, integer *n, integer *nb, doublereal *
	a, integer *lda, doublereal *d__, doublereal *e, doublereal *tauq, 
	doublereal *taup, doublereal *x, integer *ldx, doublereal *y, integer 
	*ldy);
 
/* Subroutine */ extern "C" int dlacon_(integer *n, doublereal *v, doublereal *x, 
	integer *isgn, doublereal *est, integer *kase);
 
/* Subroutine */ extern "C" int dlacpy_(char *uplo, integer *m, integer *n, doublereal *
	a, integer *lda, doublereal *b, integer *ldb);
 
/* Subroutine */ extern "C" int dladiv_(doublereal *a, doublereal *b, doublereal *c__, 
	doublereal *d__, doublereal *p, doublereal *q);
 
/* Subroutine */ extern "C" int dlae2_(doublereal *a, doublereal *b, doublereal *c__, 
	doublereal *rt1, doublereal *rt2);
 
/* Subroutine */ extern "C" int dlaebz_(integer *ijob, integer *nitmax, integer *n, 
	integer *mmax, integer *minp, integer *nbmin, doublereal *abstol, 
	doublereal *reltol, doublereal *pivmin, doublereal *d__, doublereal *
	e, doublereal *e2, integer *nval, doublereal *ab, doublereal *c__, 
	integer *mout, integer *nab, doublereal *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dlaed0_(integer *icompq, integer *qsiz, integer *n, 
	doublereal *d__, doublereal *e, doublereal *q, integer *ldq, 
	doublereal *qstore, integer *ldqs, doublereal *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dlaed1_(integer *n, doublereal *d__, doublereal *q, 
	integer *ldq, integer *indxq, doublereal *rho, integer *cutpnt, 
	doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dlaed2_(integer *k, integer *n, integer *n1, doublereal *
	d__, doublereal *q, integer *ldq, integer *indxq, doublereal *rho, 
	doublereal *z__, doublereal *dlamda, doublereal *w, doublereal *q2, 
	integer *indx, integer *indxc, integer *indxp, integer *coltyp, 
	integer *info);
 
/* Subroutine */ extern "C" int dlaed3_(integer *k, integer *n, integer *n1, doublereal *
	d__, doublereal *q, integer *ldq, doublereal *rho, doublereal *dlamda,
	 doublereal *q2, integer *indx, integer *ctot, doublereal *w, 
	doublereal *s, integer *info);
 
/* Subroutine */ extern "C" int dlaed4_(integer *n, integer *i__, doublereal *d__, 
	doublereal *z__, doublereal *delta, doublereal *rho, doublereal *dlam,
	 integer *info);
 
/* Subroutine */ extern "C" int dlaed5_(integer *i__, doublereal *d__, doublereal *z__, 
	doublereal *delta, doublereal *rho, doublereal *dlam);
 
/* Subroutine */ extern "C" int dlaed6_(integer *kniter, logical *orgati, doublereal *
	rho, doublereal *d__, doublereal *z__, doublereal *finit, doublereal *
	tau, integer *info);
 
/* Subroutine */ extern "C" int dlaed7_(integer *icompq, integer *n, integer *qsiz, 
	integer *tlvls, integer *curlvl, integer *curpbm, doublereal *d__, 
	doublereal *q, integer *ldq, integer *indxq, doublereal *rho, integer 
	*cutpnt, doublereal *qstore, integer *qptr, integer *prmptr, integer *
	perm, integer *givptr, integer *givcol, doublereal *givnum, 
	doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dlaed8_(integer *icompq, integer *k, integer *n, integer 
	*qsiz, doublereal *d__, doublereal *q, integer *ldq, integer *indxq, 
	doublereal *rho, integer *cutpnt, doublereal *z__, doublereal *dlamda,
	 doublereal *q2, integer *ldq2, doublereal *w, integer *perm, integer 
	*givptr, integer *givcol, doublereal *givnum, integer *indxp, integer 
	*indx, integer *info);
 
/* Subroutine */ extern "C" int dlaed9_(integer *k, integer *kstart, integer *kstop, 
	integer *n, doublereal *d__, doublereal *q, integer *ldq, doublereal *
	rho, doublereal *dlamda, doublereal *w, doublereal *s, integer *lds, 
	integer *info);
 
/* Subroutine */ extern "C" int dlaeda_(integer *n, integer *tlvls, integer *curlvl, 
	integer *curpbm, integer *prmptr, integer *perm, integer *givptr, 
	integer *givcol, doublereal *givnum, doublereal *q, integer *qptr, 
	doublereal *z__, doublereal *ztemp, integer *info);
 
/* Subroutine */ extern "C" int dlaein_(logical *rightv, logical *noinit, integer *n, 
	doublereal *h__, integer *ldh, doublereal *wr, doublereal *wi, 
	doublereal *vr, doublereal *vi, doublereal *b, integer *ldb, 
	doublereal *work, doublereal *eps3, doublereal *smlnum, doublereal *
	bignum, integer *info);
 
/* Subroutine */ extern "C" int dlaev2_(doublereal *a, doublereal *b, doublereal *c__, 
	doublereal *rt1, doublereal *rt2, doublereal *cs1, doublereal *sn1);
 
/* Subroutine */ extern "C" int dlaexc_(logical *wantq, integer *n, doublereal *t, 
	integer *ldt, doublereal *q, integer *ldq, integer *j1, integer *n1, 
	integer *n2, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dlag2_(doublereal *a, integer *lda, doublereal *b, 
	integer *ldb, doublereal *safmin, doublereal *scale1, doublereal *
	scale2, doublereal *wr1, doublereal *wr2, doublereal *wi);
 
/* Subroutine */ extern "C" int dlags2_(logical *upper, doublereal *a1, doublereal *a2, 
	doublereal *a3, doublereal *b1, doublereal *b2, doublereal *b3, 
	doublereal *csu, doublereal *snu, doublereal *csv, doublereal *snv, 
	doublereal *csq, doublereal *snq);
 
/* Subroutine */ extern "C" int dlagtf_(integer *n, doublereal *a, doublereal *lambda, 
	doublereal *b, doublereal *c__, doublereal *tol, doublereal *d__, 
	integer *in, integer *info);
 
/* Subroutine */ extern "C" int dlagtm_(char *trans, integer *n, integer *nrhs, 
	doublereal *alpha, doublereal *dl, doublereal *d__, doublereal *du, 
	doublereal *x, integer *ldx, doublereal *beta, doublereal *b, integer 
	*ldb);
 
/* Subroutine */ extern "C" int dlagts_(integer *job, integer *n, doublereal *a, 
	doublereal *b, doublereal *c__, doublereal *d__, integer *in, 
	doublereal *y, doublereal *tol, integer *info);
 
/* Subroutine */ extern "C" int dlagv2_(doublereal *a, integer *lda, doublereal *b, 
	integer *ldb, doublereal *alphar, doublereal *alphai, doublereal *
	beta, doublereal *csl, doublereal *snl, doublereal *csr, doublereal *
	snr);
 
/* Subroutine */ extern "C" int dlahqr_(logical *wantt, logical *wantz, integer *n, 
	integer *ilo, integer *ihi, doublereal *h__, integer *ldh, doublereal 
	*wr, doublereal *wi, integer *iloz, integer *ihiz, doublereal *z__, 
	integer *ldz, integer *info);
 
/* Subroutine */ extern "C" int dlahrd_(integer *n, integer *k, integer *nb, doublereal *
	a, integer *lda, doublereal *tau, doublereal *t, integer *ldt, 
	doublereal *y, integer *ldy);
 
/* Subroutine */ extern "C" int dlaic1_(integer *job, integer *j, doublereal *x, 
	doublereal *sest, doublereal *w, doublereal *gamma, doublereal *
	sestpr, doublereal *s, doublereal *c__);
 
/* Subroutine */ extern "C" int dlaln2_(logical *ltrans, integer *na, integer *nw, 
	doublereal *smin, doublereal *ca, doublereal *a, integer *lda, 
	doublereal *d1, doublereal *d2, doublereal *b, integer *ldb, 
	doublereal *wr, doublereal *wi, doublereal *x, integer *ldx, 
	doublereal *scale, doublereal *xnorm, integer *info);
 
/* Subroutine */ extern "C" int dlals0_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, integer *nrhs, doublereal *b, integer *ldb, doublereal 
	*bx, integer *ldbx, integer *perm, integer *givptr, integer *givcol, 
	integer *ldgcol, doublereal *givnum, integer *ldgnum, doublereal *
	poles, doublereal *difl, doublereal *difr, doublereal *z__, integer *
	k, doublereal *c__, doublereal *s, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dlalsa_(integer *icompq, integer *smlsiz, integer *n, 
	integer *nrhs, doublereal *b, integer *ldb, doublereal *bx, integer *
	ldbx, doublereal *u, integer *ldu, doublereal *vt, integer *k, 
	doublereal *difl, doublereal *difr, doublereal *z__, doublereal *
	poles, integer *givptr, integer *givcol, integer *ldgcol, integer *
	perm, doublereal *givnum, doublereal *c__, doublereal *s, doublereal *
	work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dlalsd_(char *uplo, integer *smlsiz, integer *n, integer 
	*nrhs, doublereal *d__, doublereal *e, doublereal *b, integer *ldb, 
	doublereal *rcond, integer *rank, doublereal *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dlamc1_(integer *beta, integer *t, logical *rnd, logical 
	*ieee1);
 
/* Subroutine */ extern "C" int dlamc2_(integer *beta, integer *t, logical *rnd, 
	doublereal *eps, integer *emin, doublereal *rmin, integer *emax, 
	doublereal *rmax);
 
/* Subroutine */ extern "C" int dlamc4_(integer *emin, doublereal *start, integer *base);
 
/* Subroutine */ extern "C" int dlamc5_(integer *beta, integer *p, integer *emin, 
	logical *ieee, integer *emax, doublereal *rmax);
 
/* Subroutine */ extern "C" int dlamrg_(integer *n1, integer *n2, doublereal *a, integer 
	*dtrd1, integer *dtrd2, integer *index);
 
/* Subroutine */ extern "C" int dlanv2_(doublereal *a, doublereal *b, doublereal *c__, 
	doublereal *d__, doublereal *rt1r, doublereal *rt1i, doublereal *rt2r,
	 doublereal *rt2i, doublereal *cs, doublereal *sn);
 
/* Subroutine */ extern "C" int dlapll_(integer *n, doublereal *x, integer *incx, 
	doublereal *y, integer *incy, doublereal *ssmin);
 
/* Subroutine */ extern "C" int dlapmt_(logical *forwrd, integer *m, integer *n, 
	doublereal *x, integer *ldx, integer *k);
 
/* Subroutine */ extern "C" int dlaqgb_(integer *m, integer *n, integer *kl, integer *ku,
	 doublereal *ab, integer *ldab, doublereal *r__, doublereal *c__, 
	doublereal *rowcnd, doublereal *colcnd, doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int dlaqge_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *r__, doublereal *c__, doublereal *rowcnd, doublereal 
	*colcnd, doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int dlaqp2_(integer *m, integer *n, integer *offset, 
	doublereal *a, integer *lda, integer *jpvt, doublereal *tau, 
	doublereal *vn1, doublereal *vn2, doublereal *work);
 
/* Subroutine */ extern "C" int dlaqps_(integer *m, integer *n, integer *offset, integer 
	*nb, integer *kb, doublereal *a, integer *lda, integer *jpvt, 
	doublereal *tau, doublereal *vn1, doublereal *vn2, doublereal *auxv, 
	doublereal *f, integer *ldf);
 
/* Subroutine */ extern "C" int dlaqsb_(char *uplo, integer *n, integer *kd, doublereal *
	ab, integer *ldab, doublereal *s, doublereal *scond, doublereal *amax,
	 char *equed);
 
/* Subroutine */ extern "C" int dlaqsp_(char *uplo, integer *n, doublereal *ap, 
	doublereal *s, doublereal *scond, doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int dlaqsy_(char *uplo, integer *n, doublereal *a, integer *
	lda, doublereal *s, doublereal *scond, doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int dlaqtr_(logical *ltran, logical *lreal, integer *n, 
	doublereal *t, integer *ldt, doublereal *b, doublereal *w, doublereal 
	*scale, doublereal *x, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dlar1v_(integer *n, integer *b1, integer *bn, doublereal 
	*sigma, doublereal *d__, doublereal *l, doublereal *ld, doublereal *
	lld, doublereal *gersch, doublereal *z__, doublereal *ztz, doublereal 
	*mingma, integer *r__, integer *isuppz, doublereal *work);
 
/* Subroutine */ extern "C" int dlar2v_(integer *n, doublereal *x, doublereal *y, 
	doublereal *z__, integer *incx, doublereal *c__, doublereal *s, 
	integer *incc);
 
/* Subroutine */ extern "C" int dlarf_(char *side, integer *m, integer *n, doublereal *v,
	 integer *incv, doublereal *tau, doublereal *c__, integer *ldc, 
	doublereal *work);
 
/* Subroutine */ extern "C" int dlarfb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, doublereal *v, integer *
	ldv, doublereal *t, integer *ldt, doublereal *c__, integer *ldc, 
	doublereal *work, integer *ldwork);
 
/* Subroutine */ extern "C" int dlarfg_(integer *n, doublereal *alpha, doublereal *x, 
	integer *incx, doublereal *tau);
 
/* Subroutine */ extern "C" int dlarft_(char *direct, char *storev, integer *n, integer *
	k, doublereal *v, integer *ldv, doublereal *tau, doublereal *t, 
	integer *ldt);
 
/* Subroutine */ extern "C" int dlarfx_(char *side, integer *m, integer *n, doublereal *
	v, doublereal *tau, doublereal *c__, integer *ldc, doublereal *work);
 
/* Subroutine */ extern "C" int dlargv_(integer *n, doublereal *x, integer *incx, 
	doublereal *y, integer *incy, doublereal *c__, integer *incc);
 
/* Subroutine */ extern "C" int dlarnv_(integer *idist, integer *iseed, integer *n, 
	doublereal *x);
 
/* Subroutine */ extern "C" int dlarrb_(integer *n, doublereal *d__, doublereal *l, 
	doublereal *ld, doublereal *lld, integer *ifirst, integer *ilast, 
	doublereal *sigma, doublereal *reltol, doublereal *w, doublereal *
	wgap, doublereal *werr, doublereal *work, integer *iwork, integer *
	info);
 
/* Subroutine */ extern "C" int dlarre_(integer *n, doublereal *d__, doublereal *e, 
	doublereal *tol, integer *nsplit, integer *isplit, integer *m, 
	doublereal *w, doublereal *woff, doublereal *gersch, doublereal *work,
	 integer *info);
 
/* Subroutine */ extern "C" int dlarrf_(integer *n, doublereal *d__, doublereal *l, 
	doublereal *ld, doublereal *lld, integer *ifirst, integer *ilast, 
	doublereal *w, doublereal *dplus, doublereal *lplus, doublereal *work,
	 integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dlarrv_(integer *n, doublereal *d__, doublereal *l, 
	integer *isplit, integer *m, doublereal *w, integer *iblock, 
	doublereal *gersch, doublereal *tol, doublereal *z__, integer *ldz, 
	integer *isuppz, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dlartg_(doublereal *f, doublereal *g, doublereal *cs, 
	doublereal *sn, doublereal *r__);
 
/* Subroutine */ extern "C" int dlartv_(integer *n, doublereal *x, integer *incx, 
	doublereal *y, integer *incy, doublereal *c__, doublereal *s, integer 
	*incc);
 
/* Subroutine */ extern "C" int dlaruv_(integer *iseed, integer *n, doublereal *x);
 
/* Subroutine */ extern "C" int dlarz_(char *side, integer *m, integer *n, integer *l, 
	doublereal *v, integer *incv, doublereal *tau, doublereal *c__, 
	integer *ldc, doublereal *work);
 
/* Subroutine */ extern "C" int dlarzb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, integer *l, doublereal *v,
	 integer *ldv, doublereal *t, integer *ldt, doublereal *c__, integer *
	ldc, doublereal *work, integer *ldwork);
 
/* Subroutine */ extern "C" int dlarzt_(char *direct, char *storev, integer *n, integer *
	k, doublereal *v, integer *ldv, doublereal *tau, doublereal *t, 
	integer *ldt);
 
/* Subroutine */ extern "C" int dlas2_(doublereal *f, doublereal *g, doublereal *h__, 
	doublereal *ssmin, doublereal *ssmax);
 
/* Subroutine */ extern "C" int dlascl_(char *type__, integer *kl, integer *ku, 
	doublereal *cfrom, doublereal *cto, integer *m, integer *n, 
	doublereal *a, integer *lda, integer *info);
 
/* Subroutine */ extern "C" int dlasd0_(integer *n, integer *sqre, doublereal *d__, 
	doublereal *e, doublereal *u, integer *ldu, doublereal *vt, integer *
	ldvt, integer *smlsiz, integer *iwork, doublereal *work, integer *
	info);
 
/* Subroutine */ extern "C" int dlasd1_(integer *nl, integer *nr, integer *sqre, 
	doublereal *d__, doublereal *alpha, doublereal *beta, doublereal *u, 
	integer *ldu, doublereal *vt, integer *ldvt, integer *idxq, integer *
	iwork, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dlasd2_(integer *nl, integer *nr, integer *sqre, integer 
	*k, doublereal *d__, doublereal *z__, doublereal *alpha, doublereal *
	beta, doublereal *u, integer *ldu, doublereal *vt, integer *ldvt, 
	doublereal *dsigma, doublereal *u2, integer *ldu2, doublereal *vt2, 
	integer *ldvt2, integer *idxp, integer *idx, integer *idxc, integer *
	idxq, integer *coltyp, integer *info);
 
/* Subroutine */ extern "C" int dlasd3_(integer *nl, integer *nr, integer *sqre, integer 
	*k, doublereal *d__, doublereal *q, integer *ldq, doublereal *dsigma, 
	doublereal *u, integer *ldu, doublereal *u2, integer *ldu2, 
	doublereal *vt, integer *ldvt, doublereal *vt2, integer *ldvt2, 
	integer *idxc, integer *ctot, doublereal *z__, integer *info);
 
/* Subroutine */ extern "C" int dlasd4_(integer *n, integer *i__, doublereal *d__, 
	doublereal *z__, doublereal *delta, doublereal *rho, doublereal *
	sigma, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dlasd5_(integer *i__, doublereal *d__, doublereal *z__, 
	doublereal *delta, doublereal *rho, doublereal *dsigma, doublereal *
	work);
 
/* Subroutine */ extern "C" int dlasd6_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, doublereal *d__, doublereal *vf, doublereal *vl, 
	doublereal *alpha, doublereal *beta, integer *idxq, integer *perm, 
	integer *givptr, integer *givcol, integer *ldgcol, doublereal *givnum,
	 integer *ldgnum, doublereal *poles, doublereal *difl, doublereal *
	difr, doublereal *z__, integer *k, doublereal *c__, doublereal *s, 
	doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dlasd7_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, integer *k, doublereal *d__, doublereal *z__, 
	doublereal *zw, doublereal *vf, doublereal *vfw, doublereal *vl, 
	doublereal *vlw, doublereal *alpha, doublereal *beta, doublereal *
	dsigma, integer *idx, integer *idxp, integer *idxq, integer *perm, 
	integer *givptr, integer *givcol, integer *ldgcol, doublereal *givnum,
	 integer *ldgnum, doublereal *c__, doublereal *s, integer *info);
 
/* Subroutine */ extern "C" int dlasd8_(integer *icompq, integer *k, doublereal *d__, 
	doublereal *z__, doublereal *vf, doublereal *vl, doublereal *difl, 
	doublereal *difr, integer *lddifr, doublereal *dsigma, doublereal *
	work, integer *info);
 
/* Subroutine */ extern "C" int dlasd9_(integer *icompq, integer *ldu, integer *k, 
	doublereal *d__, doublereal *z__, doublereal *vf, doublereal *vl, 
	doublereal *difl, doublereal *difr, doublereal *dsigma, doublereal *
	work, integer *info);
 
/* Subroutine */ extern "C" int dlasda_(integer *icompq, integer *smlsiz, integer *n, 
	integer *sqre, doublereal *d__, doublereal *e, doublereal *u, integer 
	*ldu, doublereal *vt, integer *k, doublereal *difl, doublereal *difr, 
	doublereal *z__, doublereal *poles, integer *givptr, integer *givcol, 
	integer *ldgcol, integer *perm, doublereal *givnum, doublereal *c__, 
	doublereal *s, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dlasdq_(char *uplo, integer *sqre, integer *n, integer *
	ncvt, integer *nru, integer *ncc, doublereal *d__, doublereal *e, 
	doublereal *vt, integer *ldvt, doublereal *u, integer *ldu, 
	doublereal *c__, integer *ldc, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dlasdt_(integer *n, integer *lvl, integer *nd, integer *
	inode, integer *ndiml, integer *ndimr, integer *msub);
 
/* Subroutine */ extern "C" int dlaset_(char *uplo, integer *m, integer *n, doublereal *
	alpha, doublereal *beta, doublereal *a, integer *lda);
 
/* Subroutine */ extern "C" int dlasq1_(integer *n, doublereal *d__, doublereal *e, 
	doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dlasq2_(integer *n, doublereal *z__, integer *info);
 
/* Subroutine */ extern "C" int dlasq3_(integer *i0, integer *n0, doublereal *z__, 
	integer *pp, doublereal *dmin__, doublereal *sigma, doublereal *desig,
	 doublereal *qmax, integer *nfail, integer *iter, integer *ndiv, 
	logical *ieee);
 
/* Subroutine */ extern "C" int dlasq4_(integer *i0, integer *n0, doublereal *z__, 
	integer *pp, integer *n0in, doublereal *dmin__, doublereal *dmin1, 
	doublereal *dmin2, doublereal *dn, doublereal *dn1, doublereal *dn2, 
	doublereal *tau, integer *ttype);
 
/* Subroutine */ extern "C" int dlasq5_(integer *i0, integer *n0, doublereal *z__, 
	integer *pp, doublereal *tau, doublereal *dmin__, doublereal *dmin1, 
	doublereal *dmin2, doublereal *dn, doublereal *dnm1, doublereal *dnm2,
	 logical *ieee);
 
/* Subroutine */ extern "C" int dlasq6_(integer *i0, integer *n0, doublereal *z__, 
	integer *pp, doublereal *dmin__, doublereal *dmin1, doublereal *dmin2,
	 doublereal *dn, doublereal *dnm1, doublereal *dnm2);
 
/* Subroutine */ extern "C" int dlasr_(char *side, char *pivot, char *direct, integer *m,
	 integer *n, doublereal *c__, doublereal *s, doublereal *a, integer *
	lda);
 
/* Subroutine */ extern "C" int dlasrt_(char *id, integer *n, doublereal *d__, integer *
	info);
 
/* Subroutine */ extern "C" int dlassq_(integer *n, doublereal *x, integer *incx, 
	doublereal *scale, doublereal *sumsq);
 
/* Subroutine */ extern "C" int dlasv2_(doublereal *f, doublereal *g, doublereal *h__, 
	doublereal *ssmin, doublereal *ssmax, doublereal *snr, doublereal *
	csr, doublereal *snl, doublereal *csl);
 
/* Subroutine */ extern "C" int dlaswp_(integer *n, doublereal *a, integer *lda, integer 
	*k1, integer *k2, integer *ipiv, integer *incx);
 
/* Subroutine */ extern "C" int dlasy2_(logical *ltranl, logical *ltranr, integer *isgn, 
	integer *n1, integer *n2, doublereal *tl, integer *ldtl, doublereal *
	tr, integer *ldtr, doublereal *b, integer *ldb, doublereal *scale, 
	doublereal *x, integer *ldx, doublereal *xnorm, integer *info);
 
/* Subroutine */ extern "C" int dlasyf_(char *uplo, integer *n, integer *nb, integer *kb,
	 doublereal *a, integer *lda, integer *ipiv, doublereal *w, integer *
	ldw, integer *info);
 
/* Subroutine */ extern "C" int dlatbs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, integer *kd, doublereal *ab, integer *ldab, 
	doublereal *x, doublereal *scale, doublereal *cnorm, integer *info);
 
/* Subroutine */ extern "C" int dlatdf_(integer *ijob, integer *n, doublereal *z__, 
	integer *ldz, doublereal *rhs, doublereal *rdsum, doublereal *rdscal, 
	integer *ipiv, integer *jpiv);
 
/* Subroutine */ extern "C" int dlatps_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, doublereal *ap, doublereal *x, doublereal *scale, 
	doublereal *cnorm, integer *info);
 
/* Subroutine */ extern "C" int dlatrd_(char *uplo, integer *n, integer *nb, doublereal *
	a, integer *lda, doublereal *e, doublereal *tau, doublereal *w, 
	integer *ldw);
 
/* Subroutine */ extern "C" int dlatrs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, doublereal *a, integer *lda, doublereal *x, 
	doublereal *scale, doublereal *cnorm, integer *info);
 
/* Subroutine */ extern "C" int dlatrz_(integer *m, integer *n, integer *l, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work);
 
/* Subroutine */ extern "C" int dlatzm_(char *side, integer *m, integer *n, doublereal *
	v, integer *incv, doublereal *tau, doublereal *c1, doublereal *c2, 
	integer *ldc, doublereal *work);
 
/* Subroutine */ extern "C" int dlauu2_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *info);
 
/* Subroutine */ extern "C" int dlauum_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *info);
 
/* Subroutine */ extern "C" int dopgtr_(char *uplo, integer *n, doublereal *ap, 
	doublereal *tau, doublereal *q, integer *ldq, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int dopmtr_(char *side, char *uplo, char *trans, integer *m, 
	integer *n, doublereal *ap, doublereal *tau, doublereal *c__, integer 
	*ldc, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dorg2l_(integer *m, integer *n, integer *k, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dorg2r_(integer *m, integer *n, integer *k, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dorgbr_(char *vect, integer *m, integer *n, integer *k, 
	doublereal *a, integer *lda, doublereal *tau, doublereal *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dorghr_(integer *n, integer *ilo, integer *ihi, 
	doublereal *a, integer *lda, doublereal *tau, doublereal *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dorgl2_(integer *m, integer *n, integer *k, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dorglq_(integer *m, integer *n, integer *k, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dorgql_(integer *m, integer *n, integer *k, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dorgqr_(integer *m, integer *n, integer *k, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dorgr2_(integer *m, integer *n, integer *k, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dorgrq_(integer *m, integer *n, integer *k, doublereal *
	a, integer *lda, doublereal *tau, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dorgtr_(char *uplo, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dorm2l_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dorm2r_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dormbr_(char *vect, char *side, char *trans, integer *m, 
	integer *n, integer *k, doublereal *a, integer *lda, doublereal *tau, 
	doublereal *c__, integer *ldc, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dormhr_(char *side, char *trans, integer *m, integer *n, 
	integer *ilo, integer *ihi, doublereal *a, integer *lda, doublereal *
	tau, doublereal *c__, integer *ldc, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dorml2_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dormlq_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dormql_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dormqr_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dormr2_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dormr3_(char *side, char *trans, integer *m, integer *n, 
	integer *k, integer *l, doublereal *a, integer *lda, doublereal *tau, 
	doublereal *c__, integer *ldc, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dormrq_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dormrz_(char *side, char *trans, integer *m, integer *n, 
	integer *k, integer *l, doublereal *a, integer *lda, doublereal *tau, 
	doublereal *c__, integer *ldc, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dormtr_(char *side, char *uplo, char *trans, integer *m, 
	integer *n, doublereal *a, integer *lda, doublereal *tau, doublereal *
	c__, integer *ldc, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dpbcon_(char *uplo, integer *n, integer *kd, doublereal *
	ab, integer *ldab, doublereal *anorm, doublereal *rcond, doublereal *
	work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dpbequ_(char *uplo, integer *n, integer *kd, doublereal *
	ab, integer *ldab, doublereal *s, doublereal *scond, doublereal *amax,
	 integer *info);
 
/* Subroutine */ extern "C" int dpbrfs_(char *uplo, integer *n, integer *kd, integer *
	nrhs, doublereal *ab, integer *ldab, doublereal *afb, integer *ldafb, 
	doublereal *b, integer *ldb, doublereal *x, integer *ldx, doublereal *
	ferr, doublereal *berr, doublereal *work, integer *iwork, integer *
	info);
 
/* Subroutine */ extern "C" int dpbstf_(char *uplo, integer *n, integer *kd, doublereal *
	ab, integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int dpbsv_(char *uplo, integer *n, integer *kd, integer *
	nrhs, doublereal *ab, integer *ldab, doublereal *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int dpbsvx_(char *fact, char *uplo, integer *n, integer *kd, 
	integer *nrhs, doublereal *ab, integer *ldab, doublereal *afb, 
	integer *ldafb, char *equed, doublereal *s, doublereal *b, integer *
	ldb, doublereal *x, integer *ldx, doublereal *rcond, doublereal *ferr,
	 doublereal *berr, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dpbtf2_(char *uplo, integer *n, integer *kd, doublereal *
	ab, integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int dpbtrf_(char *uplo, integer *n, integer *kd, doublereal *
	ab, integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int dpbtrs_(char *uplo, integer *n, integer *kd, integer *
	nrhs, doublereal *ab, integer *ldab, doublereal *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int dpocon_(char *uplo, integer *n, doublereal *a, integer *
	lda, doublereal *anorm, doublereal *rcond, doublereal *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dpoequ_(integer *n, doublereal *a, integer *lda, 
	doublereal *s, doublereal *scond, doublereal *amax, integer *info);
 
/* Subroutine */ extern "C" int dporfs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, doublereal *af, integer *ldaf, 
	doublereal *b, integer *ldb, doublereal *x, integer *ldx, doublereal *
	ferr, doublereal *berr, doublereal *work, integer *iwork, integer *
	info);
 
/* Subroutine */ extern "C" int dposv_(char *uplo, integer *n, integer *nrhs, doublereal 
	*a, integer *lda, doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dposvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublereal *a, integer *lda, doublereal *af, integer *ldaf, 
	char *equed, doublereal *s, doublereal *b, integer *ldb, doublereal *
	x, integer *ldx, doublereal *rcond, doublereal *ferr, doublereal *
	berr, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dpotf2_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *info);
 
/* Subroutine */ extern "C" int dpotrf_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *info);
 
/* Subroutine */ extern "C" int dpotri_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *info);
 
/* Subroutine */ extern "C" int dpotrs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int dppcon_(char *uplo, integer *n, doublereal *ap, 
	doublereal *anorm, doublereal *rcond, doublereal *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dppequ_(char *uplo, integer *n, doublereal *ap, 
	doublereal *s, doublereal *scond, doublereal *amax, integer *info);
 
/* Subroutine */ extern "C" int dpprfs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *ap, doublereal *afp, doublereal *b, integer *ldb, 
	doublereal *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dppsv_(char *uplo, integer *n, integer *nrhs, doublereal 
	*ap, doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dppsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublereal *ap, doublereal *afp, char *equed, doublereal *s, 
	doublereal *b, integer *ldb, doublereal *x, integer *ldx, doublereal *
	rcond, doublereal *ferr, doublereal *berr, doublereal *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dpptrf_(char *uplo, integer *n, doublereal *ap, integer *
	info);
 
/* Subroutine */ extern "C" int dpptri_(char *uplo, integer *n, doublereal *ap, integer *
	info);
 
/* Subroutine */ extern "C" int dpptrs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *ap, doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dptcon_(integer *n, doublereal *d__, doublereal *e, 
	doublereal *anorm, doublereal *rcond, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dpteqr_(char *compz, integer *n, doublereal *d__, 
	doublereal *e, doublereal *z__, integer *ldz, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int dptrfs_(integer *n, integer *nrhs, doublereal *d__, 
	doublereal *e, doublereal *df, doublereal *ef, doublereal *b, integer 
	*ldb, doublereal *x, integer *ldx, doublereal *ferr, doublereal *berr,
	 doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dptsv_(integer *n, integer *nrhs, doublereal *d__, 
	doublereal *e, doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dptsvx_(char *fact, integer *n, integer *nrhs, 
	doublereal *d__, doublereal *e, doublereal *df, doublereal *ef, 
	doublereal *b, integer *ldb, doublereal *x, integer *ldx, doublereal *
	rcond, doublereal *ferr, doublereal *berr, doublereal *work, integer *
	info);
 
/* Subroutine */ extern "C" int dpttrf_(integer *n, doublereal *d__, doublereal *e, 
	integer *info);
 
/* Subroutine */ extern "C" int dpttrs_(integer *n, integer *nrhs, doublereal *d__, 
	doublereal *e, doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dptts2_(integer *n, integer *nrhs, doublereal *d__, 
	doublereal *e, doublereal *b, integer *ldb);
 
/* Subroutine */ extern "C" int drscl_(integer *n, doublereal *sa, doublereal *sx, 
	integer *incx);
 
/* Subroutine */ extern "C" int dsbev_(char *jobz, char *uplo, integer *n, integer *kd, 
	doublereal *ab, integer *ldab, doublereal *w, doublereal *z__, 
	integer *ldz, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dsbevd_(char *jobz, char *uplo, integer *n, integer *kd, 
	doublereal *ab, integer *ldab, doublereal *w, doublereal *z__, 
	integer *ldz, doublereal *work, integer *lwork, integer *iwork, 
	integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dsbevx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *kd, doublereal *ab, integer *ldab, doublereal *q, integer *
	ldq, doublereal *vl, doublereal *vu, integer *il, integer *iu, 
	doublereal *abstol, integer *m, doublereal *w, doublereal *z__, 
	integer *ldz, doublereal *work, integer *iwork, integer *ifail, 
	integer *info);
 
/* Subroutine */ extern "C" int dsbgst_(char *vect, char *uplo, integer *n, integer *ka, 
	integer *kb, doublereal *ab, integer *ldab, doublereal *bb, integer *
	ldbb, doublereal *x, integer *ldx, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dsbgv_(char *jobz, char *uplo, integer *n, integer *ka, 
	integer *kb, doublereal *ab, integer *ldab, doublereal *bb, integer *
	ldbb, doublereal *w, doublereal *z__, integer *ldz, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int dsbgvd_(char *jobz, char *uplo, integer *n, integer *ka, 
	integer *kb, doublereal *ab, integer *ldab, doublereal *bb, integer *
	ldbb, doublereal *w, doublereal *z__, integer *ldz, doublereal *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dsbgvx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *ka, integer *kb, doublereal *ab, integer *ldab, doublereal *
	bb, integer *ldbb, doublereal *q, integer *ldq, doublereal *vl, 
	doublereal *vu, integer *il, integer *iu, doublereal *abstol, integer 
	*m, doublereal *w, doublereal *z__, integer *ldz, doublereal *work, 
	integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int dsbtrd_(char *vect, char *uplo, integer *n, integer *kd, 
	doublereal *ab, integer *ldab, doublereal *d__, doublereal *e, 
	doublereal *q, integer *ldq, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dspcon_(char *uplo, integer *n, doublereal *ap, integer *
	ipiv, doublereal *anorm, doublereal *rcond, doublereal *work, integer 
	*iwork, integer *info);
 
/* Subroutine */ extern "C" int dspev_(char *jobz, char *uplo, integer *n, doublereal *
	ap, doublereal *w, doublereal *z__, integer *ldz, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int dspevd_(char *jobz, char *uplo, integer *n, doublereal *
	ap, doublereal *w, doublereal *z__, integer *ldz, doublereal *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dspevx_(char *jobz, char *range, char *uplo, integer *n, 
	doublereal *ap, doublereal *vl, doublereal *vu, integer *il, integer *
	iu, doublereal *abstol, integer *m, doublereal *w, doublereal *z__, 
	integer *ldz, doublereal *work, integer *iwork, integer *ifail, 
	integer *info);
 
/* Subroutine */ extern "C" int dspgst_(integer *itype, char *uplo, integer *n, 
	doublereal *ap, doublereal *bp, integer *info);
 
/* Subroutine */ extern "C" int dspgv_(integer *itype, char *jobz, char *uplo, integer *
	n, doublereal *ap, doublereal *bp, doublereal *w, doublereal *z__, 
	integer *ldz, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dspgvd_(integer *itype, char *jobz, char *uplo, integer *
	n, doublereal *ap, doublereal *bp, doublereal *w, doublereal *z__, 
	integer *ldz, doublereal *work, integer *lwork, integer *iwork, 
	integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dspgvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, doublereal *ap, doublereal *bp, doublereal *vl, 
	doublereal *vu, integer *il, integer *iu, doublereal *abstol, integer 
	*m, doublereal *w, doublereal *z__, integer *ldz, doublereal *work, 
	integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int dsprfs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *ap, doublereal *afp, integer *ipiv, doublereal *b, 
	integer *ldb, doublereal *x, integer *ldx, doublereal *ferr, 
	doublereal *berr, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dspsv_(char *uplo, integer *n, integer *nrhs, doublereal 
	*ap, integer *ipiv, doublereal *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dspsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublereal *ap, doublereal *afp, integer *ipiv, doublereal *b, 
	integer *ldb, doublereal *x, integer *ldx, doublereal *rcond, 
	doublereal *ferr, doublereal *berr, doublereal *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dsptrd_(char *uplo, integer *n, doublereal *ap, 
	doublereal *d__, doublereal *e, doublereal *tau, integer *info);
 
/* Subroutine */ extern "C" int dsptrf_(char *uplo, integer *n, doublereal *ap, integer *
	ipiv, integer *info);
 
/* Subroutine */ extern "C" int dsptri_(char *uplo, integer *n, doublereal *ap, integer *
	ipiv, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dsptrs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *ap, integer *ipiv, doublereal *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int dstebz_(char *range, char *order, integer *n, doublereal 
	*vl, doublereal *vu, integer *il, integer *iu, doublereal *abstol, 
	doublereal *d__, doublereal *e, integer *m, integer *nsplit, 
	doublereal *w, integer *iblock, integer *isplit, doublereal *work, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dstedc_(char *compz, integer *n, doublereal *d__, 
	doublereal *e, doublereal *z__, integer *ldz, doublereal *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dstegr_(char *jobz, char *range, integer *n, doublereal *
	d__, doublereal *e, doublereal *vl, doublereal *vu, integer *il, 
	integer *iu, doublereal *abstol, integer *m, doublereal *w, 
	doublereal *z__, integer *ldz, integer *isuppz, doublereal *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dstein_(integer *n, doublereal *d__, doublereal *e, 
	integer *m, doublereal *w, integer *iblock, integer *isplit, 
	doublereal *z__, integer *ldz, doublereal *work, integer *iwork, 
	integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int dsteqr_(char *compz, integer *n, doublereal *d__, 
	doublereal *e, doublereal *z__, integer *ldz, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int dsterf_(integer *n, doublereal *d__, doublereal *e, 
	integer *info);
 
/* Subroutine */ extern "C" int dstev_(char *jobz, integer *n, doublereal *d__, 
	doublereal *e, doublereal *z__, integer *ldz, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int dstevd_(char *jobz, integer *n, doublereal *d__, 
	doublereal *e, doublereal *z__, integer *ldz, doublereal *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dstevr_(char *jobz, char *range, integer *n, doublereal *
	d__, doublereal *e, doublereal *vl, doublereal *vu, integer *il, 
	integer *iu, doublereal *abstol, integer *m, doublereal *w, 
	doublereal *z__, integer *ldz, integer *isuppz, doublereal *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dstevx_(char *jobz, char *range, integer *n, doublereal *
	d__, doublereal *e, doublereal *vl, doublereal *vu, integer *il, 
	integer *iu, doublereal *abstol, integer *m, doublereal *w, 
	doublereal *z__, integer *ldz, doublereal *work, integer *iwork, 
	integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int dsycon_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *ipiv, doublereal *anorm, doublereal *rcond, doublereal *
	work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dsyev_(char *jobz, char *uplo, integer *n, doublereal *a,
	 integer *lda, doublereal *w, doublereal *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dsyevd_(char *jobz, char *uplo, integer *n, doublereal *
	a, integer *lda, doublereal *w, doublereal *work, integer *lwork, 
	integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dsyevr_(char *jobz, char *range, char *uplo, integer *n, 
	doublereal *a, integer *lda, doublereal *vl, doublereal *vu, integer *
	il, integer *iu, doublereal *abstol, integer *m, doublereal *w, 
	doublereal *z__, integer *ldz, integer *isuppz, doublereal *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dsyevx_(char *jobz, char *range, char *uplo, integer *n, 
	doublereal *a, integer *lda, doublereal *vl, doublereal *vu, integer *
	il, integer *iu, doublereal *abstol, integer *m, doublereal *w, 
	doublereal *z__, integer *ldz, doublereal *work, integer *lwork, 
	integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int dsygs2_(integer *itype, char *uplo, integer *n, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int dsygst_(integer *itype, char *uplo, integer *n, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int dsygv_(integer *itype, char *jobz, char *uplo, integer *
	n, doublereal *a, integer *lda, doublereal *b, integer *ldb, 
	doublereal *w, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dsygvd_(integer *itype, char *jobz, char *uplo, integer *
	n, doublereal *a, integer *lda, doublereal *b, integer *ldb, 
	doublereal *w, doublereal *work, integer *lwork, integer *iwork, 
	integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int dsygvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, doublereal *a, integer *lda, doublereal *b, integer 
	*ldb, doublereal *vl, doublereal *vu, integer *il, integer *iu, 
	doublereal *abstol, integer *m, doublereal *w, doublereal *z__, 
	integer *ldz, doublereal *work, integer *lwork, integer *iwork, 
	integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int dsyrfs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, doublereal *af, integer *ldaf, integer *
	ipiv, doublereal *b, integer *ldb, doublereal *x, integer *ldx, 
	doublereal *ferr, doublereal *berr, doublereal *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dsysv_(char *uplo, integer *n, integer *nrhs, doublereal 
	*a, integer *lda, integer *ipiv, doublereal *b, integer *ldb, 
	doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dsysvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublereal *a, integer *lda, doublereal *af, integer *ldaf, 
	integer *ipiv, doublereal *b, integer *ldb, doublereal *x, integer *
	ldx, doublereal *rcond, doublereal *ferr, doublereal *berr, 
	doublereal *work, integer *lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dsytd2_(char *uplo, integer *n, doublereal *a, integer *
	lda, doublereal *d__, doublereal *e, doublereal *tau, integer *info);
 
/* Subroutine */ extern "C" int dsytf2_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int dsytrd_(char *uplo, integer *n, doublereal *a, integer *
	lda, doublereal *d__, doublereal *e, doublereal *tau, doublereal *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dsytrf_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *ipiv, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dsytri_(char *uplo, integer *n, doublereal *a, integer *
	lda, integer *ipiv, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dsytrs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *a, integer *lda, integer *ipiv, doublereal *b, integer *
	ldb, integer *info);
 
/* Subroutine */ extern "C" int dtbcon_(char *norm, char *uplo, char *diag, integer *n, 
	integer *kd, doublereal *ab, integer *ldab, doublereal *rcond, 
	doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dtbrfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *kd, integer *nrhs, doublereal *ab, integer *ldab, doublereal 
	*b, integer *ldb, doublereal *x, integer *ldx, doublereal *ferr, 
	doublereal *berr, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dtbtrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *kd, integer *nrhs, doublereal *ab, integer *ldab, doublereal 
	*b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int dtgevc_(char *side, char *howmny, logical *select, 
	integer *n, doublereal *a, integer *lda, doublereal *b, integer *ldb, 
	doublereal *vl, integer *ldvl, doublereal *vr, integer *ldvr, integer 
	*mm, integer *m, doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dtgex2_(logical *wantq, logical *wantz, integer *n, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *
	q, integer *ldq, doublereal *z__, integer *ldz, integer *j1, integer *
	n1, integer *n2, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dtgexc_(logical *wantq, logical *wantz, integer *n, 
	doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *
	q, integer *ldq, doublereal *z__, integer *ldz, integer *ifst, 
	integer *ilst, doublereal *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int dtgsen_(integer *ijob, logical *wantq, logical *wantz, 
	logical *select, integer *n, doublereal *a, integer *lda, doublereal *
	b, integer *ldb, doublereal *alphar, doublereal *alphai, doublereal *
	beta, doublereal *q, integer *ldq, doublereal *z__, integer *ldz, 
	integer *m, doublereal *pl, doublereal *pr, doublereal *dif, 
	doublereal *work, integer *lwork, integer *iwork, integer *liwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dtgsja_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, integer *k, integer *l, doublereal *a, 
	integer *lda, doublereal *b, integer *ldb, doublereal *tola, 
	doublereal *tolb, doublereal *alpha, doublereal *beta, doublereal *u, 
	integer *ldu, doublereal *v, integer *ldv, doublereal *q, integer *
	ldq, doublereal *work, integer *ncycle, integer *info);
 
/* Subroutine */ extern "C" int dtgsna_(char *job, char *howmny, logical *select, 
	integer *n, doublereal *a, integer *lda, doublereal *b, integer *ldb, 
	doublereal *vl, integer *ldvl, doublereal *vr, integer *ldvr, 
	doublereal *s, doublereal *dif, integer *mm, integer *m, doublereal *
	work, integer *lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dtgsy2_(char *trans, integer *ijob, integer *m, integer *
	n, doublereal *a, integer *lda, doublereal *b, integer *ldb, 
	doublereal *c__, integer *ldc, doublereal *d__, integer *ldd, 
	doublereal *e, integer *lde, doublereal *f, integer *ldf, doublereal *
	scale, doublereal *rdsum, doublereal *rdscal, integer *iwork, integer 
	*pq, integer *info);
 
/* Subroutine */ extern "C" int dtgsyl_(char *trans, integer *ijob, integer *m, integer *
	n, doublereal *a, integer *lda, doublereal *b, integer *ldb, 
	doublereal *c__, integer *ldc, doublereal *d__, integer *ldd, 
	doublereal *e, integer *lde, doublereal *f, integer *ldf, doublereal *
	scale, doublereal *dif, doublereal *work, integer *lwork, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dtpcon_(char *norm, char *uplo, char *diag, integer *n, 
	doublereal *ap, doublereal *rcond, doublereal *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int dtprfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublereal *ap, doublereal *b, integer *ldb, 
	doublereal *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dtptri_(char *uplo, char *diag, integer *n, doublereal *
	ap, integer *info);
 
/* Subroutine */ extern "C" int dtptrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublereal *ap, doublereal *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int dtrcon_(char *norm, char *uplo, char *diag, integer *n, 
	doublereal *a, integer *lda, doublereal *rcond, doublereal *work, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dtrevc_(char *side, char *howmny, logical *select, 
	integer *n, doublereal *t, integer *ldt, doublereal *vl, integer *
	ldvl, doublereal *vr, integer *ldvr, integer *mm, integer *m, 
	doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dtrexc_(char *compq, integer *n, doublereal *t, integer *
	ldt, doublereal *q, integer *ldq, integer *ifst, integer *ilst, 
	doublereal *work, integer *info);
 
/* Subroutine */ extern "C" int dtrrfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublereal *a, integer *lda, doublereal *b, integer *
	ldb, doublereal *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int dtrsen_(char *job, char *compq, logical *select, integer 
	*n, doublereal *t, integer *ldt, doublereal *q, integer *ldq, 
	doublereal *wr, doublereal *wi, integer *m, doublereal *s, doublereal 
	*sep, doublereal *work, integer *lwork, integer *iwork, integer *
	liwork, integer *info);
 
/* Subroutine */ extern "C" int dtrsna_(char *job, char *howmny, logical *select, 
	integer *n, doublereal *t, integer *ldt, doublereal *vl, integer *
	ldvl, doublereal *vr, integer *ldvr, doublereal *s, doublereal *sep, 
	integer *mm, integer *m, doublereal *work, integer *ldwork, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int dtrsyl_(char *trana, char *tranb, integer *isgn, integer 
	*m, integer *n, doublereal *a, integer *lda, doublereal *b, integer *
	ldb, doublereal *c__, integer *ldc, doublereal *scale, integer *info);
 
/* Subroutine */ extern "C" int dtrti2_(char *uplo, char *diag, integer *n, doublereal *
	a, integer *lda, integer *info);
 
/* Subroutine */ extern "C" int dtrtri_(char *uplo, char *diag, integer *n, doublereal *
	a, integer *lda, integer *info);
 
/* Subroutine */ extern "C" int dtrtrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublereal *a, integer *lda, doublereal *b, integer *
	ldb, integer *info);
 
/* Subroutine */ extern "C" int dtzrqf_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, integer *info);
 
/* Subroutine */ extern "C" int dtzrzf_(integer *m, integer *n, doublereal *a, integer *
	lda, doublereal *tau, doublereal *work, integer *lwork, integer *info);
 
integer icmax1_(integer *n, complex *cx, integer *incx);
 
integer ieeeck_(integer *ispec, real *zero, real *one);
 
integer ilaenv_(integer *ispec, char *name__, char *opts, integer *n1, 
	integer *n2, integer *n3, integer *n4, ftnlen name_len, ftnlen 
	opts_len);
 
integer izmax1_(integer *n, doublecomplex *cx, integer *incx);
 
/* Subroutine */ extern "C" int sbdsdc_(char *uplo, char *compq, integer *n, real *d__, 
	real *e, real *u, integer *ldu, real *vt, integer *ldvt, real *q, 
	integer *iq, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sbdsqr_(char *uplo, integer *n, integer *ncvt, integer *
	nru, integer *ncc, real *d__, real *e, real *vt, integer *ldvt, real *
	u, integer *ldu, real *c__, integer *ldc, real *work, integer *info);
 
/* Subroutine */ extern "C" int sdisna_(char *job, integer *m, integer *n, real *d__, 
	real *sep, integer *info);
 
/* Subroutine */ extern "C" int sgbbrd_(char *vect, integer *m, integer *n, integer *ncc,
	 integer *kl, integer *ku, real *ab, integer *ldab, real *d__, real *
	e, real *q, integer *ldq, real *pt, integer *ldpt, real *c__, integer 
	*ldc, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgbcon_(char *norm, integer *n, integer *kl, integer *ku,
	 real *ab, integer *ldab, integer *ipiv, real *anorm, real *rcond, 
	real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgbequ_(integer *m, integer *n, integer *kl, integer *ku,
	 real *ab, integer *ldab, real *r__, real *c__, real *rowcnd, real *
	colcnd, real *amax, integer *info);
 
/* Subroutine */ extern "C" int sgbrfs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, real *ab, integer *ldab, real *afb, integer *ldafb,
	 integer *ipiv, real *b, integer *ldb, real *x, integer *ldx, real *
	ferr, real *berr, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgbsv_(integer *n, integer *kl, integer *ku, integer *
	nrhs, real *ab, integer *ldab, integer *ipiv, real *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int sgbsvx_(char *fact, char *trans, integer *n, integer *kl,
	 integer *ku, integer *nrhs, real *ab, integer *ldab, real *afb, 
	integer *ldafb, integer *ipiv, char *equed, real *r__, real *c__, 
	real *b, integer *ldb, real *x, integer *ldx, real *rcond, real *ferr,
	 real *berr, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgbtf2_(integer *m, integer *n, integer *kl, integer *ku,
	 real *ab, integer *ldab, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int sgbtrf_(integer *m, integer *n, integer *kl, integer *ku,
	 real *ab, integer *ldab, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int sgbtrs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, real *ab, integer *ldab, integer *ipiv, real *b, 
	integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sgebak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, real *scale, integer *m, real *v, integer *ldv, integer 
	*info);
 
/* Subroutine */ extern "C" int sgebal_(char *job, integer *n, real *a, integer *lda, 
	integer *ilo, integer *ihi, real *scale, integer *info);
 
/* Subroutine */ extern "C" int sgebd2_(integer *m, integer *n, real *a, integer *lda, 
	real *d__, real *e, real *tauq, real *taup, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgebrd_(integer *m, integer *n, real *a, integer *lda, 
	real *d__, real *e, real *tauq, real *taup, real *work, integer *
	lwork, integer *info);
 
/* Subroutine */ extern "C" int sgecon_(char *norm, integer *n, real *a, integer *lda, 
	real *anorm, real *rcond, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgeequ_(integer *m, integer *n, real *a, integer *lda, 
	real *r__, real *c__, real *rowcnd, real *colcnd, real *amax, integer 
	*info);
 
/* Subroutine */ extern "C" int sgees_(char *jobvs, char *sort, L_fp select, integer *n, 
	real *a, integer *lda, integer *sdim, real *wr, real *wi, real *vs, 
	integer *ldvs, real *work, integer *lwork, logical *bwork, integer *
	info);
 
/* Subroutine */ extern "C" int sgeesx_(char *jobvs, char *sort, L_fp select, char *
	sense, integer *n, real *a, integer *lda, integer *sdim, real *wr, 
	real *wi, real *vs, integer *ldvs, real *rconde, real *rcondv, real *
	work, integer *lwork, integer *iwork, integer *liwork, logical *bwork,
	 integer *info);
 
/* Subroutine */ extern "C" int sgeev_(char *jobvl, char *jobvr, integer *n, real *a, 
	integer *lda, real *wr, real *wi, real *vl, integer *ldvl, real *vr, 
	integer *ldvr, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgeevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, real *a, integer *lda, real *wr, real *wi, real *
	vl, integer *ldvl, real *vr, integer *ldvr, integer *ilo, integer *
	ihi, real *scale, real *abnrm, real *rconde, real *rcondv, real *work,
	 integer *lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgegs_(char *jobvsl, char *jobvsr, integer *n, real *a, 
	integer *lda, real *b, integer *ldb, real *alphar, real *alphai, real 
	*beta, real *vsl, integer *ldvsl, real *vsr, integer *ldvsr, real *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgegv_(char *jobvl, char *jobvr, integer *n, real *a, 
	integer *lda, real *b, integer *ldb, real *alphar, real *alphai, real 
	*beta, real *vl, integer *ldvl, real *vr, integer *ldvr, real *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgehd2_(integer *n, integer *ilo, integer *ihi, real *a, 
	integer *lda, real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgehrd_(integer *n, integer *ilo, integer *ihi, real *a, 
	integer *lda, real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgelq2_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgelqf_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgels_(char *trans, integer *m, integer *n, integer *
	nrhs, real *a, integer *lda, real *b, integer *ldb, real *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgelsd_(integer *m, integer *n, integer *nrhs, real *a, 
	integer *lda, real *b, integer *ldb, real *s, real *rcond, integer *
	rank, real *work, integer *lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgelss_(integer *m, integer *n, integer *nrhs, real *a, 
	integer *lda, real *b, integer *ldb, real *s, real *rcond, integer *
	rank, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgelsx_(integer *m, integer *n, integer *nrhs, real *a, 
	integer *lda, real *b, integer *ldb, integer *jpvt, real *rcond, 
	integer *rank, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgelsy_(integer *m, integer *n, integer *nrhs, real *a, 
	integer *lda, real *b, integer *ldb, integer *jpvt, real *rcond, 
	integer *rank, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgeql2_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgeqlf_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgeqp3_(integer *m, integer *n, real *a, integer *lda, 
	integer *jpvt, real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgeqpf_(integer *m, integer *n, real *a, integer *lda, 
	integer *jpvt, real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgeqr2_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgeqrf_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgerfs_(char *trans, integer *n, integer *nrhs, real *a, 
	integer *lda, real *af, integer *ldaf, integer *ipiv, real *b, 
	integer *ldb, real *x, integer *ldx, real *ferr, real *berr, real *
	work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgerq2_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgerqf_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgesc2_(integer *n, real *a, integer *lda, real *rhs, 
	integer *ipiv, integer *jpiv, real *scale);
 
/* Subroutine */ extern "C" int sgesdd_(char *jobz, integer *m, integer *n, real *a, 
	integer *lda, real *s, real *u, integer *ldu, real *vt, integer *ldvt,
	 real *work, integer *lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgesv_(integer *n, integer *nrhs, real *a, integer *lda, 
	integer *ipiv, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sgesvd_(char *jobu, char *jobvt, integer *m, integer *n, 
	real *a, integer *lda, real *s, real *u, integer *ldu, real *vt, 
	integer *ldvt, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgesvx_(char *fact, char *trans, integer *n, integer *
	nrhs, real *a, integer *lda, real *af, integer *ldaf, integer *ipiv, 
	char *equed, real *r__, real *c__, real *b, integer *ldb, real *x, 
	integer *ldx, real *rcond, real *ferr, real *berr, real *work, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgetc2_(integer *n, real *a, integer *lda, integer *ipiv,
	 integer *jpiv, integer *info);
 
/* Subroutine */ extern "C" int sgetf2_(integer *m, integer *n, real *a, integer *lda, 
	integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int sgetrf_(integer *m, integer *n, real *a, integer *lda, 
	integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int sgetri_(integer *n, real *a, integer *lda, integer *ipiv,
	 real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgetrs_(char *trans, integer *n, integer *nrhs, real *a, 
	integer *lda, integer *ipiv, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sggbak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, real *lscale, real *rscale, integer *m, real *v, 
	integer *ldv, integer *info);
 
/* Subroutine */ extern "C" int sggbal_(char *job, integer *n, real *a, integer *lda, 
	real *b, integer *ldb, integer *ilo, integer *ihi, real *lscale, real 
	*rscale, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgges_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	selctg, integer *n, real *a, integer *lda, real *b, integer *ldb, 
	integer *sdim, real *alphar, real *alphai, real *beta, real *vsl, 
	integer *ldvsl, real *vsr, integer *ldvsr, real *work, integer *lwork,
	 logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int sggesx_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	selctg, char *sense, integer *n, real *a, integer *lda, real *b, 
	integer *ldb, integer *sdim, real *alphar, real *alphai, real *beta, 
	real *vsl, integer *ldvsl, real *vsr, integer *ldvsr, real *rconde, 
	real *rcondv, real *work, integer *lwork, integer *iwork, integer *
	liwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int sggev_(char *jobvl, char *jobvr, integer *n, real *a, 
	integer *lda, real *b, integer *ldb, real *alphar, real *alphai, real 
	*beta, real *vl, integer *ldvl, real *vr, integer *ldvr, real *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sggevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, real *a, integer *lda, real *b, integer *ldb, real 
	*alphar, real *alphai, real *beta, real *vl, integer *ldvl, real *vr, 
	integer *ldvr, integer *ilo, integer *ihi, real *lscale, real *rscale,
	 real *abnrm, real *bbnrm, real *rconde, real *rcondv, real *work, 
	integer *lwork, integer *iwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int sggglm_(integer *n, integer *m, integer *p, real *a, 
	integer *lda, real *b, integer *ldb, real *d__, real *x, real *y, 
	real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sgghrd_(char *compq, char *compz, integer *n, integer *
	ilo, integer *ihi, real *a, integer *lda, real *b, integer *ldb, real 
	*q, integer *ldq, real *z__, integer *ldz, integer *info);
 
/* Subroutine */ extern "C" int sgglse_(integer *m, integer *n, integer *p, real *a, 
	integer *lda, real *b, integer *ldb, real *c__, real *d__, real *x, 
	real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sggqrf_(integer *n, integer *m, integer *p, real *a, 
	integer *lda, real *taua, real *b, integer *ldb, real *taub, real *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sggrqf_(integer *m, integer *p, integer *n, real *a, 
	integer *lda, real *taua, real *b, integer *ldb, real *taub, real *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sggsvd_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *n, integer *p, integer *k, integer *l, real *a, integer *lda,
	 real *b, integer *ldb, real *alpha, real *beta, real *u, integer *
	ldu, real *v, integer *ldv, real *q, integer *ldq, real *work, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sggsvp_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, real *a, integer *lda, real *b, integer *ldb, 
	real *tola, real *tolb, integer *k, integer *l, real *u, integer *ldu,
	 real *v, integer *ldv, real *q, integer *ldq, integer *iwork, real *
	tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sgtcon_(char *norm, integer *n, real *dl, real *d__, 
	real *du, real *du2, integer *ipiv, real *anorm, real *rcond, real *
	work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgtrfs_(char *trans, integer *n, integer *nrhs, real *dl,
	 real *d__, real *du, real *dlf, real *df, real *duf, real *du2, 
	integer *ipiv, real *b, integer *ldb, real *x, integer *ldx, real *
	ferr, real *berr, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sgtsv_(integer *n, integer *nrhs, real *dl, real *d__, 
	real *du, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sgtsvx_(char *fact, char *trans, integer *n, integer *
	nrhs, real *dl, real *d__, real *du, real *dlf, real *df, real *duf, 
	real *du2, integer *ipiv, real *b, integer *ldb, real *x, integer *
	ldx, real *rcond, real *ferr, real *berr, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int sgttrf_(integer *n, real *dl, real *d__, real *du, real *
	du2, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int sgttrs_(char *trans, integer *n, integer *nrhs, real *dl,
	 real *d__, real *du, real *du2, integer *ipiv, real *b, integer *ldb,
	 integer *info);
 
/* Subroutine */ extern "C" int sgtts2_(integer *itrans, integer *n, integer *nrhs, real 
	*dl, real *d__, real *du, real *du2, integer *ipiv, real *b, integer *
	ldb);
 
/* Subroutine */ extern "C" int shgeqz_(char *job, char *compq, char *compz, integer *n, 
	integer *ilo, integer *ihi, real *a, integer *lda, real *b, integer *
	ldb, real *alphar, real *alphai, real *beta, real *q, integer *ldq, 
	real *z__, integer *ldz, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int shsein_(char *side, char *eigsrc, char *initv, logical *
	select, integer *n, real *h__, integer *ldh, real *wr, real *wi, real 
	*vl, integer *ldvl, real *vr, integer *ldvr, integer *mm, integer *m, 
	real *work, integer *ifaill, integer *ifailr, integer *info);
 
/* Subroutine */ extern "C" int shseqr_(char *job, char *compz, integer *n, integer *ilo,
	 integer *ihi, real *h__, integer *ldh, real *wr, real *wi, real *z__,
	 integer *ldz, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int slabad_(real *small, real *large);
 
/* Subroutine */ extern "C" int slabrd_(integer *m, integer *n, integer *nb, real *a, 
	integer *lda, real *d__, real *e, real *tauq, real *taup, real *x, 
	integer *ldx, real *y, integer *ldy);
 
/* Subroutine */ extern "C" int slacon_(integer *n, real *v, real *x, integer *isgn, 
	real *est, integer *kase);
 
/* Subroutine */ extern "C" int slacpy_(char *uplo, integer *m, integer *n, real *a, 
	integer *lda, real *b, integer *ldb);
 
/* Subroutine */ extern "C" int sladiv_(real *a, real *b, real *c__, real *d__, real *p, 
	real *q);
 
/* Subroutine */ extern "C" int slae2_(real *a, real *b, real *c__, real *rt1, real *rt2);
 
/* Subroutine */ extern "C" int slaebz_(integer *ijob, integer *nitmax, integer *n, 
	integer *mmax, integer *minp, integer *nbmin, real *abstol, real *
	reltol, real *pivmin, real *d__, real *e, real *e2, integer *nval, 
	real *ab, real *c__, integer *mout, integer *nab, real *work, integer 
	*iwork, integer *info);
 
/* Subroutine */ extern "C" int slaed0_(integer *icompq, integer *qsiz, integer *n, real 
	*d__, real *e, real *q, integer *ldq, real *qstore, integer *ldqs, 
	real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int slaed1_(integer *n, real *d__, real *q, integer *ldq, 
	integer *indxq, real *rho, integer *cutpnt, real *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int slaed2_(integer *k, integer *n, integer *n1, real *d__, 
	real *q, integer *ldq, integer *indxq, real *rho, real *z__, real *
	dlamda, real *w, real *q2, integer *indx, integer *indxc, integer *
	indxp, integer *coltyp, integer *info);
 
/* Subroutine */ extern "C" int slaed3_(integer *k, integer *n, integer *n1, real *d__, 
	real *q, integer *ldq, real *rho, real *dlamda, real *q2, integer *
	indx, integer *ctot, real *w, real *s, integer *info);
 
/* Subroutine */ extern "C" int slaed4_(integer *n, integer *i__, real *d__, real *z__, 
	real *delta, real *rho, real *dlam, integer *info);
 
/* Subroutine */ extern "C" int slaed5_(integer *i__, real *d__, real *z__, real *delta, 
	real *rho, real *dlam);
 
/* Subroutine */ extern "C" int slaed6_(integer *kniter, logical *orgati, real *rho, 
	real *d__, real *z__, real *finit, real *tau, integer *info);
 
/* Subroutine */ extern "C" int slaed7_(integer *icompq, integer *n, integer *qsiz, 
	integer *tlvls, integer *curlvl, integer *curpbm, real *d__, real *q, 
	integer *ldq, integer *indxq, real *rho, integer *cutpnt, real *
	qstore, integer *qptr, integer *prmptr, integer *perm, integer *
	givptr, integer *givcol, real *givnum, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int slaed8_(integer *icompq, integer *k, integer *n, integer 
	*qsiz, real *d__, real *q, integer *ldq, integer *indxq, real *rho, 
	integer *cutpnt, real *z__, real *dlamda, real *q2, integer *ldq2, 
	real *w, integer *perm, integer *givptr, integer *givcol, real *
	givnum, integer *indxp, integer *indx, integer *info);
 
/* Subroutine */ extern "C" int slaed9_(integer *k, integer *kstart, integer *kstop, 
	integer *n, real *d__, real *q, integer *ldq, real *rho, real *dlamda,
	 real *w, real *s, integer *lds, integer *info);
 
/* Subroutine */ extern "C" int slaeda_(integer *n, integer *tlvls, integer *curlvl, 
	integer *curpbm, integer *prmptr, integer *perm, integer *givptr, 
	integer *givcol, real *givnum, real *q, integer *qptr, real *z__, 
	real *ztemp, integer *info);
 
/* Subroutine */ extern "C" int slaein_(logical *rightv, logical *noinit, integer *n, 
	real *h__, integer *ldh, real *wr, real *wi, real *vr, real *vi, real 
	*b, integer *ldb, real *work, real *eps3, real *smlnum, real *bignum, 
	integer *info);
 
/* Subroutine */ extern "C" int slaev2_(real *a, real *b, real *c__, real *rt1, real *
	rt2, real *cs1, real *sn1);
 
/* Subroutine */ extern "C" int slaexc_(logical *wantq, integer *n, real *t, integer *
	ldt, real *q, integer *ldq, integer *j1, integer *n1, integer *n2, 
	real *work, integer *info);
 
/* Subroutine */ extern "C" int slag2_(real *a, integer *lda, real *b, integer *ldb, 
	real *safmin, real *scale1, real *scale2, real *wr1, real *wr2, real *
	wi);
 
/* Subroutine */ extern "C" int slags2_(logical *upper, real *a1, real *a2, real *a3, 
	real *b1, real *b2, real *b3, real *csu, real *snu, real *csv, real *
	snv, real *csq, real *snq);
 
/* Subroutine */ extern "C" int slagtf_(integer *n, real *a, real *lambda, real *b, real 
	*c__, real *tol, real *d__, integer *in, integer *info);
 
/* Subroutine */ extern "C" int slagtm_(char *trans, integer *n, integer *nrhs, real *
	alpha, real *dl, real *d__, real *du, real *x, integer *ldx, real *
	beta, real *b, integer *ldb);
 
/* Subroutine */ extern "C" int slagts_(integer *job, integer *n, real *a, real *b, real 
	*c__, real *d__, integer *in, real *y, real *tol, integer *info);
 
/* Subroutine */ extern "C" int slagv2_(real *a, integer *lda, real *b, integer *ldb, 
	real *alphar, real *alphai, real *beta, real *csl, real *snl, real *
	csr, real *snr);
 
/* Subroutine */ extern "C" int slahqr_(logical *wantt, logical *wantz, integer *n, 
	integer *ilo, integer *ihi, real *h__, integer *ldh, real *wr, real *
	wi, integer *iloz, integer *ihiz, real *z__, integer *ldz, integer *
	info);
 
/* Subroutine */ extern "C" int slahrd_(integer *n, integer *k, integer *nb, real *a, 
	integer *lda, real *tau, real *t, integer *ldt, real *y, integer *ldy);
 
/* Subroutine */ extern "C" int slaic1_(integer *job, integer *j, real *x, real *sest, 
	real *w, real *gamma, real *sestpr, real *s, real *c__);
 
/* Subroutine */ extern "C" int slaln2_(logical *ltrans, integer *na, integer *nw, real *
	smin, real *ca, real *a, integer *lda, real *d1, real *d2, real *b, 
	integer *ldb, real *wr, real *wi, real *x, integer *ldx, real *scale, 
	real *xnorm, integer *info);
 
/* Subroutine */ extern "C" int slals0_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, integer *nrhs, real *b, integer *ldb, real *bx, 
	integer *ldbx, integer *perm, integer *givptr, integer *givcol, 
	integer *ldgcol, real *givnum, integer *ldgnum, real *poles, real *
	difl, real *difr, real *z__, integer *k, real *c__, real *s, real *
	work, integer *info);
 
/* Subroutine */ extern "C" int slalsa_(integer *icompq, integer *smlsiz, integer *n, 
	integer *nrhs, real *b, integer *ldb, real *bx, integer *ldbx, real *
	u, integer *ldu, real *vt, integer *k, real *difl, real *difr, real *
	z__, real *poles, integer *givptr, integer *givcol, integer *ldgcol, 
	integer *perm, real *givnum, real *c__, real *s, real *work, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int slalsd_(char *uplo, integer *smlsiz, integer *n, integer 
	*nrhs, real *d__, real *e, real *b, integer *ldb, real *rcond, 
	integer *rank, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int slamc1_(integer *beta, integer *t, logical *rnd, logical 
	*ieee1);
 
/* Subroutine */ extern "C" int slamc2_(integer *beta, integer *t, logical *rnd, real *
	eps, integer *emin, real *rmin, integer *emax, real *rmax);
 
/* Subroutine */ extern "C" int slamc4_(integer *emin, real *start, integer *base);
 
/* Subroutine */ extern "C" int slamc5_(integer *beta, integer *p, integer *emin, 
	logical *ieee, integer *emax, real *rmax);
 
/* Subroutine */ extern "C" int slamrg_(integer *n1, integer *n2, real *a, integer *
	strd1, integer *strd2, integer *index);
 
/* Subroutine */ extern "C" int slanv2_(real *a, real *b, real *c__, real *d__, real *
	rt1r, real *rt1i, real *rt2r, real *rt2i, real *cs, real *sn);
 
/* Subroutine */ extern "C" int slapll_(integer *n, real *x, integer *incx, real *y, 
	integer *incy, real *ssmin);
 
/* Subroutine */ extern "C" int slapmt_(logical *forwrd, integer *m, integer *n, real *x,
	 integer *ldx, integer *k);
 
/* Subroutine */ extern "C" int slaqgb_(integer *m, integer *n, integer *kl, integer *ku,
	 real *ab, integer *ldab, real *r__, real *c__, real *rowcnd, real *
	colcnd, real *amax, char *equed);
 
/* Subroutine */ extern "C" int slaqge_(integer *m, integer *n, real *a, integer *lda, 
	real *r__, real *c__, real *rowcnd, real *colcnd, real *amax, char *
	equed);
 
/* Subroutine */ extern "C" int slaqp2_(integer *m, integer *n, integer *offset, real *a,
	 integer *lda, integer *jpvt, real *tau, real *vn1, real *vn2, real *
	work);
 
/* Subroutine */ extern "C" int slaqps_(integer *m, integer *n, integer *offset, integer 
	*nb, integer *kb, real *a, integer *lda, integer *jpvt, real *tau, 
	real *vn1, real *vn2, real *auxv, real *f, integer *ldf);
 
/* Subroutine */ extern "C" int slaqsb_(char *uplo, integer *n, integer *kd, real *ab, 
	integer *ldab, real *s, real *scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int slaqsp_(char *uplo, integer *n, real *ap, real *s, real *
	scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int slaqsy_(char *uplo, integer *n, real *a, integer *lda, 
	real *s, real *scond, real *amax, char *equed);
 
/* Subroutine */ extern "C" int slaqtr_(logical *ltran, logical *lreal, integer *n, real 
	*t, integer *ldt, real *b, real *w, real *scale, real *x, real *work, 
	integer *info);
 
/* Subroutine */ extern "C" int slar1v_(integer *n, integer *b1, integer *bn, real *
	sigma, real *d__, real *l, real *ld, real *lld, real *gersch, real *
	z__, real *ztz, real *mingma, integer *r__, integer *isuppz, real *
	work);
 
/* Subroutine */ extern "C" int slar2v_(integer *n, real *x, real *y, real *z__, integer 
	*incx, real *c__, real *s, integer *incc);
 
/* Subroutine */ extern "C" int slarf_(char *side, integer *m, integer *n, real *v, 
	integer *incv, real *tau, real *c__, integer *ldc, real *work);
 
/* Subroutine */ extern "C" int slarfb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, real *v, integer *ldv, 
	real *t, integer *ldt, real *c__, integer *ldc, real *work, integer *
	ldwork);
 
/* Subroutine */ extern "C" int slarfg_(integer *n, real *alpha, real *x, integer *incx, 
	real *tau);
 
/* Subroutine */ extern "C" int slarft_(char *direct, char *storev, integer *n, integer *
	k, real *v, integer *ldv, real *tau, real *t, integer *ldt);
 
/* Subroutine */ extern "C" int slarfx_(char *side, integer *m, integer *n, real *v, 
	real *tau, real *c__, integer *ldc, real *work);
 
/* Subroutine */ extern "C" int slargv_(integer *n, real *x, integer *incx, real *y, 
	integer *incy, real *c__, integer *incc);
 
/* Subroutine */ extern "C" int slarnv_(integer *idist, integer *iseed, integer *n, real 
	*x);
 
/* Subroutine */ extern "C" int slarrb_(integer *n, real *d__, real *l, real *ld, real *
	lld, integer *ifirst, integer *ilast, real *sigma, real *reltol, real 
	*w, real *wgap, real *werr, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int slarre_(integer *n, real *d__, real *e, real *tol, 
	integer *nsplit, integer *isplit, integer *m, real *w, real *woff, 
	real *gersch, real *work, integer *info);
 
/* Subroutine */ extern "C" int slarrf_(integer *n, real *d__, real *l, real *ld, real *
	lld, integer *ifirst, integer *ilast, real *w, real *dplus, real *
	lplus, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int slarrv_(integer *n, real *d__, real *l, integer *isplit, 
	integer *m, real *w, integer *iblock, real *gersch, real *tol, real *
	z__, integer *ldz, integer *isuppz, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int slartg_(real *f, real *g, real *cs, real *sn, real *r__);
 
/* Subroutine */ extern "C" int slartv_(integer *n, real *x, integer *incx, real *y, 
	integer *incy, real *c__, real *s, integer *incc);
 
/* Subroutine */ extern "C" int slaruv_(integer *iseed, integer *n, real *x);
 
/* Subroutine */ extern "C" int slarz_(char *side, integer *m, integer *n, integer *l, 
	real *v, integer *incv, real *tau, real *c__, integer *ldc, real *
	work);
 
/* Subroutine */ extern "C" int slarzb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, integer *l, real *v, 
	integer *ldv, real *t, integer *ldt, real *c__, integer *ldc, real *
	work, integer *ldwork);
 
/* Subroutine */ extern "C" int slarzt_(char *direct, char *storev, integer *n, integer *
	k, real *v, integer *ldv, real *tau, real *t, integer *ldt);
 
/* Subroutine */ extern "C" int slas2_(real *f, real *g, real *h__, real *ssmin, real *
	ssmax);
 
/* Subroutine */ extern "C" int slascl_(char *type__, integer *kl, integer *ku, real *
	cfrom, real *cto, integer *m, integer *n, real *a, integer *lda, 
	integer *info);
 
/* Subroutine */ extern "C" int slasd0_(integer *n, integer *sqre, real *d__, real *e, 
	real *u, integer *ldu, real *vt, integer *ldvt, integer *smlsiz, 
	integer *iwork, real *work, integer *info);
 
/* Subroutine */ extern "C" int slasd1_(integer *nl, integer *nr, integer *sqre, real *
	d__, real *alpha, real *beta, real *u, integer *ldu, real *vt, 
	integer *ldvt, integer *idxq, integer *iwork, real *work, integer *
	info);
 
/* Subroutine */ extern "C" int slasd2_(integer *nl, integer *nr, integer *sqre, integer 
	*k, real *d__, real *z__, real *alpha, real *beta, real *u, integer *
	ldu, real *vt, integer *ldvt, real *dsigma, real *u2, integer *ldu2, 
	real *vt2, integer *ldvt2, integer *idxp, integer *idx, integer *idxc,
	 integer *idxq, integer *coltyp, integer *info);
 
/* Subroutine */ extern "C" int slasd3_(integer *nl, integer *nr, integer *sqre, integer 
	*k, real *d__, real *q, integer *ldq, real *dsigma, real *u, integer *
	ldu, real *u2, integer *ldu2, real *vt, integer *ldvt, real *vt2, 
	integer *ldvt2, integer *idxc, integer *ctot, real *z__, integer *
	info);
 
/* Subroutine */ extern "C" int slasd4_(integer *n, integer *i__, real *d__, real *z__, 
	real *delta, real *rho, real *sigma, real *work, integer *info);
 
/* Subroutine */ extern "C" int slasd5_(integer *i__, real *d__, real *z__, real *delta, 
	real *rho, real *dsigma, real *work);
 
/* Subroutine */ extern "C" int slasd6_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, real *d__, real *vf, real *vl, real *alpha, real *beta,
	 integer *idxq, integer *perm, integer *givptr, integer *givcol, 
	integer *ldgcol, real *givnum, integer *ldgnum, real *poles, real *
	difl, real *difr, real *z__, integer *k, real *c__, real *s, real *
	work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int slasd7_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, integer *k, real *d__, real *z__, real *zw, real *vf, 
	real *vfw, real *vl, real *vlw, real *alpha, real *beta, real *dsigma,
	 integer *idx, integer *idxp, integer *idxq, integer *perm, integer *
	givptr, integer *givcol, integer *ldgcol, real *givnum, integer *
	ldgnum, real *c__, real *s, integer *info);
 
/* Subroutine */ extern "C" int slasd8_(integer *icompq, integer *k, real *d__, real *
	z__, real *vf, real *vl, real *difl, real *difr, integer *lddifr, 
	real *dsigma, real *work, integer *info);
 
/* Subroutine */ extern "C" int slasd9_(integer *icompq, integer *ldu, integer *k, real *
	d__, real *z__, real *vf, real *vl, real *difl, real *difr, real *
	dsigma, real *work, integer *info);
 
/* Subroutine */ extern "C" int slasda_(integer *icompq, integer *smlsiz, integer *n, 
	integer *sqre, real *d__, real *e, real *u, integer *ldu, real *vt, 
	integer *k, real *difl, real *difr, real *z__, real *poles, integer *
	givptr, integer *givcol, integer *ldgcol, integer *perm, real *givnum,
	 real *c__, real *s, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int slasdq_(char *uplo, integer *sqre, integer *n, integer *
	ncvt, integer *nru, integer *ncc, real *d__, real *e, real *vt, 
	integer *ldvt, real *u, integer *ldu, real *c__, integer *ldc, real *
	work, integer *info);
 
/* Subroutine */ extern "C" int slasdt_(integer *n, integer *lvl, integer *nd, integer *
	inode, integer *ndiml, integer *ndimr, integer *msub);
 
/* Subroutine */ extern "C" int slaset_(char *uplo, integer *m, integer *n, real *alpha, 
	real *beta, real *a, integer *lda);
 
/* Subroutine */ extern "C" int slasq1_(integer *n, real *d__, real *e, real *work, 
	integer *info);
 
/* Subroutine */ extern "C" int slasq2_(integer *n, real *z__, integer *info);
 
/* Subroutine */ extern "C" int slasq3_(integer *i0, integer *n0, real *z__, integer *pp,
	 real *dmin__, real *sigma, real *desig, real *qmax, integer *nfail, 
	integer *iter, integer *ndiv, logical *ieee);
 
/* Subroutine */ extern "C" int slasq4_(integer *i0, integer *n0, real *z__, integer *pp,
	 integer *n0in, real *dmin__, real *dmin1, real *dmin2, real *dn, 
	real *dn1, real *dn2, real *tau, integer *ttype);
 
/* Subroutine */ extern "C" int slasq5_(integer *i0, integer *n0, real *z__, integer *pp,
	 real *tau, real *dmin__, real *dmin1, real *dmin2, real *dn, real *
	dnm1, real *dnm2, logical *ieee);
 
/* Subroutine */ extern "C" int slasq6_(integer *i0, integer *n0, real *z__, integer *pp,
	 real *dmin__, real *dmin1, real *dmin2, real *dn, real *dnm1, real *
	dnm2);
 
/* Subroutine */ extern "C" int slasr_(char *side, char *pivot, char *direct, integer *m,
	 integer *n, real *c__, real *s, real *a, integer *lda);
 
/* Subroutine */ extern "C" int slasrt_(char *id, integer *n, real *d__, integer *info);
 
/* Subroutine */ extern "C" int slassq_(integer *n, real *x, integer *incx, real *scale, 
	real *sumsq);
 
/* Subroutine */ extern "C" int slasv2_(real *f, real *g, real *h__, real *ssmin, real *
	ssmax, real *snr, real *csr, real *snl, real *csl);
 
/* Subroutine */ extern "C" int slaswp_(integer *n, real *a, integer *lda, integer *k1, 
	integer *k2, integer *ipiv, integer *incx);
 
/* Subroutine */ extern "C" int slasy2_(logical *ltranl, logical *ltranr, integer *isgn, 
	integer *n1, integer *n2, real *tl, integer *ldtl, real *tr, integer *
	ldtr, real *b, integer *ldb, real *scale, real *x, integer *ldx, real 
	*xnorm, integer *info);
 
/* Subroutine */ extern "C" int slasyf_(char *uplo, integer *n, integer *nb, integer *kb,
	 real *a, integer *lda, integer *ipiv, real *w, integer *ldw, integer 
	*info);
 
/* Subroutine */ extern "C" int slatbs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, integer *kd, real *ab, integer *ldab, real *x, 
	real *scale, real *cnorm, integer *info);
 
/* Subroutine */ extern "C" int slatdf_(integer *ijob, integer *n, real *z__, integer *
	ldz, real *rhs, real *rdsum, real *rdscal, integer *ipiv, integer *
	jpiv);
 
/* Subroutine */ extern "C" int slatps_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, real *ap, real *x, real *scale, real *cnorm, 
	integer *info);
 
/* Subroutine */ extern "C" int slatrd_(char *uplo, integer *n, integer *nb, real *a, 
	integer *lda, real *e, real *tau, real *w, integer *ldw);
 
/* Subroutine */ extern "C" int slatrs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, real *a, integer *lda, real *x, real *scale, real 
	*cnorm, integer *info);
 
/* Subroutine */ extern "C" int slatrz_(integer *m, integer *n, integer *l, real *a, 
	integer *lda, real *tau, real *work);
 
/* Subroutine */ extern "C" int slatzm_(char *side, integer *m, integer *n, real *v, 
	integer *incv, real *tau, real *c1, real *c2, integer *ldc, real *
	work);
 
/* Subroutine */ extern "C" int slauu2_(char *uplo, integer *n, real *a, integer *lda, 
	integer *info);
 
/* Subroutine */ extern "C" int slauum_(char *uplo, integer *n, real *a, integer *lda, 
	integer *info);
 
/* Subroutine */ extern "C" int sopgtr_(char *uplo, integer *n, real *ap, real *tau, 
	real *q, integer *ldq, real *work, integer *info);
 
/* Subroutine */ extern "C" int sopmtr_(char *side, char *uplo, char *trans, integer *m, 
	integer *n, real *ap, real *tau, real *c__, integer *ldc, real *work, 
	integer *info);
 
/* Subroutine */ extern "C" int sorg2l_(integer *m, integer *n, integer *k, real *a, 
	integer *lda, real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sorg2r_(integer *m, integer *n, integer *k, real *a, 
	integer *lda, real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sorgbr_(char *vect, integer *m, integer *n, integer *k, 
	real *a, integer *lda, real *tau, real *work, integer *lwork, integer 
	*info);
 
/* Subroutine */ extern "C" int sorghr_(integer *n, integer *ilo, integer *ihi, real *a, 
	integer *lda, real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sorgl2_(integer *m, integer *n, integer *k, real *a, 
	integer *lda, real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sorglq_(integer *m, integer *n, integer *k, real *a, 
	integer *lda, real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sorgql_(integer *m, integer *n, integer *k, real *a, 
	integer *lda, real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sorgqr_(integer *m, integer *n, integer *k, real *a, 
	integer *lda, real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sorgr2_(integer *m, integer *n, integer *k, real *a, 
	integer *lda, real *tau, real *work, integer *info);
 
/* Subroutine */ extern "C" int sorgrq_(integer *m, integer *n, integer *k, real *a, 
	integer *lda, real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sorgtr_(char *uplo, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sorm2l_(char *side, char *trans, integer *m, integer *n, 
	integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *info);
 
/* Subroutine */ extern "C" int sorm2r_(char *side, char *trans, integer *m, integer *n, 
	integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *info);
 
/* Subroutine */ extern "C" int sormbr_(char *vect, char *side, char *trans, integer *m, 
	integer *n, integer *k, real *a, integer *lda, real *tau, real *c__, 
	integer *ldc, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sormhr_(char *side, char *trans, integer *m, integer *n, 
	integer *ilo, integer *ihi, real *a, integer *lda, real *tau, real *
	c__, integer *ldc, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sorml2_(char *side, char *trans, integer *m, integer *n, 
	integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *info);
 
/* Subroutine */ extern "C" int sormlq_(char *side, char *trans, integer *m, integer *n, 
	integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sormql_(char *side, char *trans, integer *m, integer *n, 
	integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sormqr_(char *side, char *trans, integer *m, integer *n, 
	integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sormr2_(char *side, char *trans, integer *m, integer *n, 
	integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *info);
 
/* Subroutine */ extern "C" int sormr3_(char *side, char *trans, integer *m, integer *n, 
	integer *k, integer *l, real *a, integer *lda, real *tau, real *c__, 
	integer *ldc, real *work, integer *info);
 
/* Subroutine */ extern "C" int sormrq_(char *side, char *trans, integer *m, integer *n, 
	integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sormrz_(char *side, char *trans, integer *m, integer *n, 
	integer *k, integer *l, real *a, integer *lda, real *tau, real *c__, 
	integer *ldc, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int sormtr_(char *side, char *uplo, char *trans, integer *m, 
	integer *n, real *a, integer *lda, real *tau, real *c__, integer *ldc,
	 real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int spbcon_(char *uplo, integer *n, integer *kd, real *ab, 
	integer *ldab, real *anorm, real *rcond, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int spbequ_(char *uplo, integer *n, integer *kd, real *ab, 
	integer *ldab, real *s, real *scond, real *amax, integer *info);
 
/* Subroutine */ extern "C" int spbrfs_(char *uplo, integer *n, integer *kd, integer *
	nrhs, real *ab, integer *ldab, real *afb, integer *ldafb, real *b, 
	integer *ldb, real *x, integer *ldx, real *ferr, real *berr, real *
	work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int spbstf_(char *uplo, integer *n, integer *kd, real *ab, 
	integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int spbsv_(char *uplo, integer *n, integer *kd, integer *
	nrhs, real *ab, integer *ldab, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int spbsvx_(char *fact, char *uplo, integer *n, integer *kd, 
	integer *nrhs, real *ab, integer *ldab, real *afb, integer *ldafb, 
	char *equed, real *s, real *b, integer *ldb, real *x, integer *ldx, 
	real *rcond, real *ferr, real *berr, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int spbtf2_(char *uplo, integer *n, integer *kd, real *ab, 
	integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int spbtrf_(char *uplo, integer *n, integer *kd, real *ab, 
	integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int spbtrs_(char *uplo, integer *n, integer *kd, integer *
	nrhs, real *ab, integer *ldab, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int spocon_(char *uplo, integer *n, real *a, integer *lda, 
	real *anorm, real *rcond, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int spoequ_(integer *n, real *a, integer *lda, real *s, real 
	*scond, real *amax, integer *info);
 
/* Subroutine */ extern "C" int sporfs_(char *uplo, integer *n, integer *nrhs, real *a, 
	integer *lda, real *af, integer *ldaf, real *b, integer *ldb, real *x,
	 integer *ldx, real *ferr, real *berr, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int sposv_(char *uplo, integer *n, integer *nrhs, real *a, 
	integer *lda, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sposvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, real *a, integer *lda, real *af, integer *ldaf, char *equed, 
	real *s, real *b, integer *ldb, real *x, integer *ldx, real *rcond, 
	real *ferr, real *berr, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int spotf2_(char *uplo, integer *n, real *a, integer *lda, 
	integer *info);
 
/* Subroutine */ extern "C" int spotrf_(char *uplo, integer *n, real *a, integer *lda, 
	integer *info);
 
/* Subroutine */ extern "C" int spotri_(char *uplo, integer *n, real *a, integer *lda, 
	integer *info);
 
/* Subroutine */ extern "C" int spotrs_(char *uplo, integer *n, integer *nrhs, real *a, 
	integer *lda, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sppcon_(char *uplo, integer *n, real *ap, real *anorm, 
	real *rcond, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sppequ_(char *uplo, integer *n, real *ap, real *s, real *
	scond, real *amax, integer *info);
 
/* Subroutine */ extern "C" int spprfs_(char *uplo, integer *n, integer *nrhs, real *ap, 
	real *afp, real *b, integer *ldb, real *x, integer *ldx, real *ferr, 
	real *berr, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sppsv_(char *uplo, integer *n, integer *nrhs, real *ap, 
	real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sppsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, real *ap, real *afp, char *equed, real *s, real *b, integer *
	ldb, real *x, integer *ldx, real *rcond, real *ferr, real *berr, real 
	*work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int spptrf_(char *uplo, integer *n, real *ap, integer *info);
 
/* Subroutine */ extern "C" int spptri_(char *uplo, integer *n, real *ap, integer *info);
 
/* Subroutine */ extern "C" int spptrs_(char *uplo, integer *n, integer *nrhs, real *ap, 
	real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sptcon_(integer *n, real *d__, real *e, real *anorm, 
	real *rcond, real *work, integer *info);
 
/* Subroutine */ extern "C" int spteqr_(char *compz, integer *n, real *d__, real *e, 
	real *z__, integer *ldz, real *work, integer *info);
 
/* Subroutine */ extern "C" int sptrfs_(integer *n, integer *nrhs, real *d__, real *e, 
	real *df, real *ef, real *b, integer *ldb, real *x, integer *ldx, 
	real *ferr, real *berr, real *work, integer *info);
 
/* Subroutine */ extern "C" int sptsv_(integer *n, integer *nrhs, real *d__, real *e, 
	real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sptsvx_(char *fact, integer *n, integer *nrhs, real *d__,
	 real *e, real *df, real *ef, real *b, integer *ldb, real *x, integer 
	*ldx, real *rcond, real *ferr, real *berr, real *work, integer *info);
 
/* Subroutine */ extern "C" int spttrf_(integer *n, real *d__, real *e, integer *info);
 
/* Subroutine */ extern "C" int spttrs_(integer *n, integer *nrhs, real *d__, real *e, 
	real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sptts2_(integer *n, integer *nrhs, real *d__, real *e, 
	real *b, integer *ldb);
 
/* Subroutine */ extern "C" int srscl_(integer *n, real *sa, real *sx, integer *incx);
 
/* Subroutine */ extern "C" int ssbev_(char *jobz, char *uplo, integer *n, integer *kd, 
	real *ab, integer *ldab, real *w, real *z__, integer *ldz, real *work,
	 integer *info);
 
/* Subroutine */ extern "C" int ssbevd_(char *jobz, char *uplo, integer *n, integer *kd, 
	real *ab, integer *ldab, real *w, real *z__, integer *ldz, real *work,
	 integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int ssbevx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *kd, real *ab, integer *ldab, real *q, integer *ldq, real *vl,
	 real *vu, integer *il, integer *iu, real *abstol, integer *m, real *
	w, real *z__, integer *ldz, real *work, integer *iwork, integer *
	ifail, integer *info);
 
/* Subroutine */ extern "C" int ssbgst_(char *vect, char *uplo, integer *n, integer *ka, 
	integer *kb, real *ab, integer *ldab, real *bb, integer *ldbb, real *
	x, integer *ldx, real *work, integer *info);
 
/* Subroutine */ extern "C" int ssbgv_(char *jobz, char *uplo, integer *n, integer *ka, 
	integer *kb, real *ab, integer *ldab, real *bb, integer *ldbb, real *
	w, real *z__, integer *ldz, real *work, integer *info);
 
/* Subroutine */ extern "C" int ssbgvd_(char *jobz, char *uplo, integer *n, integer *ka, 
	integer *kb, real *ab, integer *ldab, real *bb, integer *ldbb, real *
	w, real *z__, integer *ldz, real *work, integer *lwork, integer *
	iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int ssbgvx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *ka, integer *kb, real *ab, integer *ldab, real *bb, integer *
	ldbb, real *q, integer *ldq, real *vl, real *vu, integer *il, integer 
	*iu, real *abstol, integer *m, real *w, real *z__, integer *ldz, real 
	*work, integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int ssbtrd_(char *vect, char *uplo, integer *n, integer *kd, 
	real *ab, integer *ldab, real *d__, real *e, real *q, integer *ldq, 
	real *work, integer *info);
 
/* Subroutine */ extern "C" int sspcon_(char *uplo, integer *n, real *ap, integer *ipiv, 
	real *anorm, real *rcond, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sspev_(char *jobz, char *uplo, integer *n, real *ap, 
	real *w, real *z__, integer *ldz, real *work, integer *info);
 
/* Subroutine */ extern "C" int sspevd_(char *jobz, char *uplo, integer *n, real *ap, 
	real *w, real *z__, integer *ldz, real *work, integer *lwork, integer 
	*iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int sspevx_(char *jobz, char *range, char *uplo, integer *n, 
	real *ap, real *vl, real *vu, integer *il, integer *iu, real *abstol, 
	integer *m, real *w, real *z__, integer *ldz, real *work, integer *
	iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int sspgst_(integer *itype, char *uplo, integer *n, real *ap,
	 real *bp, integer *info);
 
/* Subroutine */ extern "C" int sspgv_(integer *itype, char *jobz, char *uplo, integer *
	n, real *ap, real *bp, real *w, real *z__, integer *ldz, real *work, 
	integer *info);
 
/* Subroutine */ extern "C" int sspgvd_(integer *itype, char *jobz, char *uplo, integer *
	n, real *ap, real *bp, real *w, real *z__, integer *ldz, real *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int sspgvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, real *ap, real *bp, real *vl, real *vu, integer *il,
	 integer *iu, real *abstol, integer *m, real *w, real *z__, integer *
	ldz, real *work, integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int ssprfs_(char *uplo, integer *n, integer *nrhs, real *ap, 
	real *afp, integer *ipiv, real *b, integer *ldb, real *x, integer *
	ldx, real *ferr, real *berr, real *work, integer *iwork, integer *
	info);
 
/* Subroutine */ extern "C" int sspsv_(char *uplo, integer *n, integer *nrhs, real *ap, 
	integer *ipiv, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sspsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, real *ap, real *afp, integer *ipiv, real *b, integer *ldb, real 
	*x, integer *ldx, real *rcond, real *ferr, real *berr, real *work, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int ssptrd_(char *uplo, integer *n, real *ap, real *d__, 
	real *e, real *tau, integer *info);
 
/* Subroutine */ extern "C" int ssptrf_(char *uplo, integer *n, real *ap, integer *ipiv, 
	integer *info);
 
/* Subroutine */ extern "C" int ssptri_(char *uplo, integer *n, real *ap, integer *ipiv, 
	real *work, integer *info);
 
/* Subroutine */ extern "C" int ssptrs_(char *uplo, integer *n, integer *nrhs, real *ap, 
	integer *ipiv, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int sstebz_(char *range, char *order, integer *n, real *vl, 
	real *vu, integer *il, integer *iu, real *abstol, real *d__, real *e, 
	integer *m, integer *nsplit, real *w, integer *iblock, integer *
	isplit, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int sstedc_(char *compz, integer *n, real *d__, real *e, 
	real *z__, integer *ldz, real *work, integer *lwork, integer *iwork, 
	integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int sstegr_(char *jobz, char *range, integer *n, real *d__, 
	real *e, real *vl, real *vu, integer *il, integer *iu, real *abstol, 
	integer *m, real *w, real *z__, integer *ldz, integer *isuppz, real *
	work, integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int sstein_(integer *n, real *d__, real *e, integer *m, real 
	*w, integer *iblock, integer *isplit, real *z__, integer *ldz, real *
	work, integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int ssteqr_(char *compz, integer *n, real *d__, real *e, 
	real *z__, integer *ldz, real *work, integer *info);
 
/* Subroutine */ extern "C" int ssterf_(integer *n, real *d__, real *e, integer *info);
 
/* Subroutine */ extern "C" int sstev_(char *jobz, integer *n, real *d__, real *e, real *
	z__, integer *ldz, real *work, integer *info);
 
/* Subroutine */ extern "C" int sstevd_(char *jobz, integer *n, real *d__, real *e, real 
	*z__, integer *ldz, real *work, integer *lwork, integer *iwork, 
	integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int sstevr_(char *jobz, char *range, integer *n, real *d__, 
	real *e, real *vl, real *vu, integer *il, integer *iu, real *abstol, 
	integer *m, real *w, real *z__, integer *ldz, integer *isuppz, real *
	work, integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int sstevx_(char *jobz, char *range, integer *n, real *d__, 
	real *e, real *vl, real *vu, integer *il, integer *iu, real *abstol, 
	integer *m, real *w, real *z__, integer *ldz, real *work, integer *
	iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int ssycon_(char *uplo, integer *n, real *a, integer *lda, 
	integer *ipiv, real *anorm, real *rcond, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int ssyev_(char *jobz, char *uplo, integer *n, real *a, 
	integer *lda, real *w, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int ssyevd_(char *jobz, char *uplo, integer *n, real *a, 
	integer *lda, real *w, real *work, integer *lwork, integer *iwork, 
	integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int ssyevr_(char *jobz, char *range, char *uplo, integer *n, 
	real *a, integer *lda, real *vl, real *vu, integer *il, integer *iu, 
	real *abstol, integer *m, real *w, real *z__, integer *ldz, integer *
	isuppz, real *work, integer *lwork, integer *iwork, integer *liwork, 
	integer *info);
 
/* Subroutine */ extern "C" int ssyevx_(char *jobz, char *range, char *uplo, integer *n, 
	real *a, integer *lda, real *vl, real *vu, integer *il, integer *iu, 
	real *abstol, integer *m, real *w, real *z__, integer *ldz, real *
	work, integer *lwork, integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int ssygs2_(integer *itype, char *uplo, integer *n, real *a, 
	integer *lda, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int ssygst_(integer *itype, char *uplo, integer *n, real *a, 
	integer *lda, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int ssygv_(integer *itype, char *jobz, char *uplo, integer *
	n, real *a, integer *lda, real *b, integer *ldb, real *w, real *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int ssygvd_(integer *itype, char *jobz, char *uplo, integer *
	n, real *a, integer *lda, real *b, integer *ldb, real *w, real *work, 
	integer *lwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int ssygvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, real *a, integer *lda, real *b, integer *ldb, real *
	vl, real *vu, integer *il, integer *iu, real *abstol, integer *m, 
	real *w, real *z__, integer *ldz, real *work, integer *lwork, integer 
	*iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int ssyrfs_(char *uplo, integer *n, integer *nrhs, real *a, 
	integer *lda, real *af, integer *ldaf, integer *ipiv, real *b, 
	integer *ldb, real *x, integer *ldx, real *ferr, real *berr, real *
	work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int ssysv_(char *uplo, integer *n, integer *nrhs, real *a, 
	integer *lda, integer *ipiv, real *b, integer *ldb, real *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int ssysvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, real *a, integer *lda, real *af, integer *ldaf, integer *ipiv, 
	real *b, integer *ldb, real *x, integer *ldx, real *rcond, real *ferr,
	 real *berr, real *work, integer *lwork, integer *iwork, integer *
	info);
 
/* Subroutine */ extern "C" int ssytd2_(char *uplo, integer *n, real *a, integer *lda, 
	real *d__, real *e, real *tau, integer *info);
 
/* Subroutine */ extern "C" int ssytf2_(char *uplo, integer *n, real *a, integer *lda, 
	integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int ssytrd_(char *uplo, integer *n, real *a, integer *lda, 
	real *d__, real *e, real *tau, real *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int ssytrf_(char *uplo, integer *n, real *a, integer *lda, 
	integer *ipiv, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int ssytri_(char *uplo, integer *n, real *a, integer *lda, 
	integer *ipiv, real *work, integer *info);
 
/* Subroutine */ extern "C" int ssytrs_(char *uplo, integer *n, integer *nrhs, real *a, 
	integer *lda, integer *ipiv, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int stbcon_(char *norm, char *uplo, char *diag, integer *n, 
	integer *kd, real *ab, integer *ldab, real *rcond, real *work, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int stbrfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *kd, integer *nrhs, real *ab, integer *ldab, real *b, integer 
	*ldb, real *x, integer *ldx, real *ferr, real *berr, real *work, 
	integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int stbtrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *kd, integer *nrhs, real *ab, integer *ldab, real *b, integer 
	*ldb, integer *info);
 
/* Subroutine */ extern "C" int stgevc_(char *side, char *howmny, logical *select, 
	integer *n, real *a, integer *lda, real *b, integer *ldb, real *vl, 
	integer *ldvl, real *vr, integer *ldvr, integer *mm, integer *m, real 
	*work, integer *info);
 
/* Subroutine */ extern "C" int stgex2_(logical *wantq, logical *wantz, integer *n, real 
	*a, integer *lda, real *b, integer *ldb, real *q, integer *ldq, real *
	z__, integer *ldz, integer *j1, integer *n1, integer *n2, real *work, 
	integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int stgexc_(logical *wantq, logical *wantz, integer *n, real 
	*a, integer *lda, real *b, integer *ldb, real *q, integer *ldq, real *
	z__, integer *ldz, integer *ifst, integer *ilst, real *work, integer *
	lwork, integer *info);
 
/* Subroutine */ extern "C" int stgsen_(integer *ijob, logical *wantq, logical *wantz, 
	logical *select, integer *n, real *a, integer *lda, real *b, integer *
	ldb, real *alphar, real *alphai, real *beta, real *q, integer *ldq, 
	real *z__, integer *ldz, integer *m, real *pl, real *pr, real *dif, 
	real *work, integer *lwork, integer *iwork, integer *liwork, integer *
	info);
 
/* Subroutine */ extern "C" int stgsja_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, integer *k, integer *l, real *a, integer *lda,
	 real *b, integer *ldb, real *tola, real *tolb, real *alpha, real *
	beta, real *u, integer *ldu, real *v, integer *ldv, real *q, integer *
	ldq, real *work, integer *ncycle, integer *info);
 
/* Subroutine */ extern "C" int stgsna_(char *job, char *howmny, logical *select, 
	integer *n, real *a, integer *lda, real *b, integer *ldb, real *vl, 
	integer *ldvl, real *vr, integer *ldvr, real *s, real *dif, integer *
	mm, integer *m, real *work, integer *lwork, integer *iwork, integer *
	info);
 
/* Subroutine */ extern "C" int stgsy2_(char *trans, integer *ijob, integer *m, integer *
	n, real *a, integer *lda, real *b, integer *ldb, real *c__, integer *
	ldc, real *d__, integer *ldd, real *e, integer *lde, real *f, integer 
	*ldf, real *scale, real *rdsum, real *rdscal, integer *iwork, integer 
	*pq, integer *info);
 
/* Subroutine */ extern "C" int stgsyl_(char *trans, integer *ijob, integer *m, integer *
	n, real *a, integer *lda, real *b, integer *ldb, real *c__, integer *
	ldc, real *d__, integer *ldd, real *e, integer *lde, real *f, integer 
	*ldf, real *scale, real *dif, real *work, integer *lwork, integer *
	iwork, integer *info);
 
/* Subroutine */ extern "C" int stpcon_(char *norm, char *uplo, char *diag, integer *n, 
	real *ap, real *rcond, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int stprfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, real *ap, real *b, integer *ldb, real *x, integer *ldx,
	 real *ferr, real *berr, real *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int stptri_(char *uplo, char *diag, integer *n, real *ap, 
	integer *info);
 
/* Subroutine */ extern "C" int stptrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, real *ap, real *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int strcon_(char *norm, char *uplo, char *diag, integer *n, 
	real *a, integer *lda, real *rcond, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int strevc_(char *side, char *howmny, logical *select, 
	integer *n, real *t, integer *ldt, real *vl, integer *ldvl, real *vr, 
	integer *ldvr, integer *mm, integer *m, real *work, integer *info);
 
/* Subroutine */ extern "C" int strexc_(char *compq, integer *n, real *t, integer *ldt, 
	real *q, integer *ldq, integer *ifst, integer *ilst, real *work, 
	integer *info);
 
/* Subroutine */ extern "C" int strrfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, real *a, integer *lda, real *b, integer *ldb, real *x, 
	integer *ldx, real *ferr, real *berr, real *work, integer *iwork, 
	integer *info);
 
/* Subroutine */ extern "C" int strsen_(char *job, char *compq, logical *select, integer 
	*n, real *t, integer *ldt, real *q, integer *ldq, real *wr, real *wi, 
	integer *m, real *s, real *sep, real *work, integer *lwork, integer *
	iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int strsna_(char *job, char *howmny, logical *select, 
	integer *n, real *t, integer *ldt, real *vl, integer *ldvl, real *vr, 
	integer *ldvr, real *s, real *sep, integer *mm, integer *m, real *
	work, integer *ldwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int strsyl_(char *trana, char *tranb, integer *isgn, integer 
	*m, integer *n, real *a, integer *lda, real *b, integer *ldb, real *
	c__, integer *ldc, real *scale, integer *info);
 
/* Subroutine */ extern "C" int strti2_(char *uplo, char *diag, integer *n, real *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int strtri_(char *uplo, char *diag, integer *n, real *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int strtrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, real *a, integer *lda, real *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int stzrqf_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, integer *info);
 
/* Subroutine */ extern "C" int stzrzf_(integer *m, integer *n, real *a, integer *lda, 
	real *tau, real *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int xerbla_(char *srname, integer *info);
 
/* Subroutine */ extern "C" int zbdsqr_(char *uplo, integer *n, integer *ncvt, integer *
	nru, integer *ncc, doublereal *d__, doublereal *e, doublecomplex *vt, 
	integer *ldvt, doublecomplex *u, integer *ldu, doublecomplex *c__, 
	integer *ldc, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zdrot_(integer *n, doublecomplex *cx, integer *incx, 
	doublecomplex *cy, integer *incy, doublereal *c__, doublereal *s);
 
/* Subroutine */ extern "C" int zdrscl_(integer *n, doublereal *sa, doublecomplex *sx, 
	integer *incx);
 
/* Subroutine */ extern "C" int zgbbrd_(char *vect, integer *m, integer *n, integer *ncc,
	 integer *kl, integer *ku, doublecomplex *ab, integer *ldab, 
	doublereal *d__, doublereal *e, doublecomplex *q, integer *ldq, 
	doublecomplex *pt, integer *ldpt, doublecomplex *c__, integer *ldc, 
	doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgbcon_(char *norm, integer *n, integer *kl, integer *ku,
	 doublecomplex *ab, integer *ldab, integer *ipiv, doublereal *anorm, 
	doublereal *rcond, doublecomplex *work, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zgbequ_(integer *m, integer *n, integer *kl, integer *ku,
	 doublecomplex *ab, integer *ldab, doublereal *r__, doublereal *c__, 
	doublereal *rowcnd, doublereal *colcnd, doublereal *amax, integer *
	info);
 
/* Subroutine */ extern "C" int zgbrfs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, doublecomplex *ab, integer *ldab, doublecomplex *
	afb, integer *ldafb, integer *ipiv, doublecomplex *b, integer *ldb, 
	doublecomplex *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgbsv_(integer *n, integer *kl, integer *ku, integer *
	nrhs, doublecomplex *ab, integer *ldab, integer *ipiv, doublecomplex *
	b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int zgbsvx_(char *fact, char *trans, integer *n, integer *kl,
	 integer *ku, integer *nrhs, doublecomplex *ab, integer *ldab, 
	doublecomplex *afb, integer *ldafb, integer *ipiv, char *equed, 
	doublereal *r__, doublereal *c__, doublecomplex *b, integer *ldb, 
	doublecomplex *x, integer *ldx, doublereal *rcond, doublereal *ferr, 
	doublereal *berr, doublecomplex *work, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zgbtf2_(integer *m, integer *n, integer *kl, integer *ku,
	 doublecomplex *ab, integer *ldab, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int zgbtrf_(integer *m, integer *n, integer *kl, integer *ku,
	 doublecomplex *ab, integer *ldab, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int zgbtrs_(char *trans, integer *n, integer *kl, integer *
	ku, integer *nrhs, doublecomplex *ab, integer *ldab, integer *ipiv, 
	doublecomplex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int zgebak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, doublereal *scale, integer *m, doublecomplex *v, 
	integer *ldv, integer *info);
 
/* Subroutine */ extern "C" int zgebal_(char *job, integer *n, doublecomplex *a, integer 
	*lda, integer *ilo, integer *ihi, doublereal *scale, integer *info);
 
/* Subroutine */ extern "C" int zgebd2_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublereal *d__, doublereal *e, doublecomplex *tauq, 
	doublecomplex *taup, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zgebrd_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublereal *d__, doublereal *e, doublecomplex *tauq, 
	doublecomplex *taup, doublecomplex *work, integer *lwork, integer *
	info);
 
/* Subroutine */ extern "C" int zgecon_(char *norm, integer *n, doublecomplex *a, 
	integer *lda, doublereal *anorm, doublereal *rcond, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgeequ_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublereal *r__, doublereal *c__, doublereal *rowcnd, 
	doublereal *colcnd, doublereal *amax, integer *info);
 
/* Subroutine */ extern "C" int zgees_(char *jobvs, char *sort, L_fp select, integer *n, 
	doublecomplex *a, integer *lda, integer *sdim, doublecomplex *w, 
	doublecomplex *vs, integer *ldvs, doublecomplex *work, integer *lwork,
	 doublereal *rwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int zgeesx_(char *jobvs, char *sort, L_fp select, char *
	sense, integer *n, doublecomplex *a, integer *lda, integer *sdim, 
	doublecomplex *w, doublecomplex *vs, integer *ldvs, doublereal *
	rconde, doublereal *rcondv, doublecomplex *work, integer *lwork, 
	doublereal *rwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int zgeev_(char *jobvl, char *jobvr, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *w, doublecomplex *vl, 
	integer *ldvl, doublecomplex *vr, integer *ldvr, doublecomplex *work, 
	integer *lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgeevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, doublecomplex *a, integer *lda, doublecomplex *w, 
	doublecomplex *vl, integer *ldvl, doublecomplex *vr, integer *ldvr, 
	integer *ilo, integer *ihi, doublereal *scale, doublereal *abnrm, 
	doublereal *rconde, doublereal *rcondv, doublecomplex *work, integer *
	lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgegs_(char *jobvsl, char *jobvsr, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *alpha, doublecomplex *beta, doublecomplex *vsl, 
	integer *ldvsl, doublecomplex *vsr, integer *ldvsr, doublecomplex *
	work, integer *lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgegv_(char *jobvl, char *jobvr, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *alpha, doublecomplex *beta, doublecomplex *vl, integer 
	*ldvl, doublecomplex *vr, integer *ldvr, doublecomplex *work, integer 
	*lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgehd2_(integer *n, integer *ilo, integer *ihi, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *info);
 
/* Subroutine */ extern "C" int zgehrd_(integer *n, integer *ilo, integer *ihi, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zgelq2_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zgelqf_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zgels_(char *trans, integer *m, integer *n, integer *
	nrhs, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zgelsx_(integer *m, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	integer *jpvt, doublereal *rcond, integer *rank, doublecomplex *work, 
	doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgelsy_(integer *m, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	integer *jpvt, doublereal *rcond, integer *rank, doublecomplex *work, 
	integer *lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgeql2_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zgeqlf_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zgeqp3_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, integer *jpvt, doublecomplex *tau, doublecomplex *work, 
	integer *lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgeqpf_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, integer *jpvt, doublecomplex *tau, doublecomplex *work, 
	doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgeqr2_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zgeqrf_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zgerfs_(char *trans, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, doublecomplex *af, integer *ldaf, 
	integer *ipiv, doublecomplex *b, integer *ldb, doublecomplex *x, 
	integer *ldx, doublereal *ferr, doublereal *berr, doublecomplex *work,
	 doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgerq2_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zgerqf_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zgesc2_(integer *n, doublecomplex *a, integer *lda, 
	doublecomplex *rhs, integer *ipiv, integer *jpiv, doublereal *scale);
 
/* Subroutine */ extern "C" int zgesv_(integer *n, integer *nrhs, doublecomplex *a, 
	integer *lda, integer *ipiv, doublecomplex *b, integer *ldb, integer *
	info);
 
/* Subroutine */ extern "C" int zgesvx_(char *fact, char *trans, integer *n, integer *
	nrhs, doublecomplex *a, integer *lda, doublecomplex *af, integer *
	ldaf, integer *ipiv, char *equed, doublereal *r__, doublereal *c__, 
	doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx, 
	doublereal *rcond, doublereal *ferr, doublereal *berr, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgetc2_(integer *n, doublecomplex *a, integer *lda, 
	integer *ipiv, integer *jpiv, integer *info);
 
/* Subroutine */ extern "C" int zgetf2_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int zgetrf_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int zgetri_(integer *n, doublecomplex *a, integer *lda, 
	integer *ipiv, doublecomplex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zgetrs_(char *trans, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, integer *ipiv, doublecomplex *b, 
	integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int zggbak_(char *job, char *side, integer *n, integer *ilo, 
	integer *ihi, doublereal *lscale, doublereal *rscale, integer *m, 
	doublecomplex *v, integer *ldv, integer *info);
 
/* Subroutine */ extern "C" int zggbal_(char *job, integer *n, doublecomplex *a, integer 
	*lda, doublecomplex *b, integer *ldb, integer *ilo, integer *ihi, 
	doublereal *lscale, doublereal *rscale, doublereal *work, integer *
	info);
 
/* Subroutine */ extern "C" int zgges_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	delctg, integer *n, doublecomplex *a, integer *lda, doublecomplex *b, 
	integer *ldb, integer *sdim, doublecomplex *alpha, doublecomplex *
	beta, doublecomplex *vsl, integer *ldvsl, doublecomplex *vsr, integer 
	*ldvsr, doublecomplex *work, integer *lwork, doublereal *rwork, 
	logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int zggesx_(char *jobvsl, char *jobvsr, char *sort, L_fp 
	delctg, char *sense, integer *n, doublecomplex *a, integer *lda, 
	doublecomplex *b, integer *ldb, integer *sdim, doublecomplex *alpha, 
	doublecomplex *beta, doublecomplex *vsl, integer *ldvsl, 
	doublecomplex *vsr, integer *ldvsr, doublereal *rconde, doublereal *
	rcondv, doublecomplex *work, integer *lwork, doublereal *rwork, 
	integer *iwork, integer *liwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int zggev_(char *jobvl, char *jobvr, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *alpha, doublecomplex *beta, doublecomplex *vl, integer 
	*ldvl, doublecomplex *vr, integer *ldvr, doublecomplex *work, integer 
	*lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zggevx_(char *balanc, char *jobvl, char *jobvr, char *
	sense, integer *n, doublecomplex *a, integer *lda, doublecomplex *b, 
	integer *ldb, doublecomplex *alpha, doublecomplex *beta, 
	doublecomplex *vl, integer *ldvl, doublecomplex *vr, integer *ldvr, 
	integer *ilo, integer *ihi, doublereal *lscale, doublereal *rscale, 
	doublereal *abnrm, doublereal *bbnrm, doublereal *rconde, doublereal *
	rcondv, doublecomplex *work, integer *lwork, doublereal *rwork, 
	integer *iwork, logical *bwork, integer *info);
 
/* Subroutine */ extern "C" int zggglm_(integer *n, integer *m, integer *p, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *d__, doublecomplex *x, doublecomplex *y, doublecomplex 
	*work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zgghrd_(char *compq, char *compz, integer *n, integer *
	ilo, integer *ihi, doublecomplex *a, integer *lda, doublecomplex *b, 
	integer *ldb, doublecomplex *q, integer *ldq, doublecomplex *z__, 
	integer *ldz, integer *info);
 
/* Subroutine */ extern "C" int zgglse_(integer *m, integer *n, integer *p, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *c__, doublecomplex *d__, doublecomplex *x, 
	doublecomplex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zggqrf_(integer *n, integer *m, integer *p, 
	doublecomplex *a, integer *lda, doublecomplex *taua, doublecomplex *b,
	 integer *ldb, doublecomplex *taub, doublecomplex *work, integer *
	lwork, integer *info);
 
/* Subroutine */ extern "C" int zggrqf_(integer *m, integer *p, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *taua, doublecomplex *b,
	 integer *ldb, doublecomplex *taub, doublecomplex *work, integer *
	lwork, integer *info);
 
/* Subroutine */ extern "C" int zggsvd_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *n, integer *p, integer *k, integer *l, doublecomplex *a, 
	integer *lda, doublecomplex *b, integer *ldb, doublereal *alpha, 
	doublereal *beta, doublecomplex *u, integer *ldu, doublecomplex *v, 
	integer *ldv, doublecomplex *q, integer *ldq, doublecomplex *work, 
	doublereal *rwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int zggsvp_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, doublecomplex *a, integer *lda, doublecomplex 
	*b, integer *ldb, doublereal *tola, doublereal *tolb, integer *k, 
	integer *l, doublecomplex *u, integer *ldu, doublecomplex *v, integer 
	*ldv, doublecomplex *q, integer *ldq, integer *iwork, doublereal *
	rwork, doublecomplex *tau, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zgtcon_(char *norm, integer *n, doublecomplex *dl, 
	doublecomplex *d__, doublecomplex *du, doublecomplex *du2, integer *
	ipiv, doublereal *anorm, doublereal *rcond, doublecomplex *work, 
	integer *info);
 
/* Subroutine */ extern "C" int zgtrfs_(char *trans, integer *n, integer *nrhs, 
	doublecomplex *dl, doublecomplex *d__, doublecomplex *du, 
	doublecomplex *dlf, doublecomplex *df, doublecomplex *duf, 
	doublecomplex *du2, integer *ipiv, doublecomplex *b, integer *ldb, 
	doublecomplex *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zgtsv_(integer *n, integer *nrhs, doublecomplex *dl, 
	doublecomplex *d__, doublecomplex *du, doublecomplex *b, integer *ldb,
	 integer *info);
 
/* Subroutine */ extern "C" int zgtsvx_(char *fact, char *trans, integer *n, integer *
	nrhs, doublecomplex *dl, doublecomplex *d__, doublecomplex *du, 
	doublecomplex *dlf, doublecomplex *df, doublecomplex *duf, 
	doublecomplex *du2, integer *ipiv, doublecomplex *b, integer *ldb, 
	doublecomplex *x, integer *ldx, doublereal *rcond, doublereal *ferr, 
	doublereal *berr, doublecomplex *work, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zgttrf_(integer *n, doublecomplex *dl, doublecomplex *
	d__, doublecomplex *du, doublecomplex *du2, integer *ipiv, integer *
	info);
 
/* Subroutine */ extern "C" int zgttrs_(char *trans, integer *n, integer *nrhs, 
	doublecomplex *dl, doublecomplex *d__, doublecomplex *du, 
	doublecomplex *du2, integer *ipiv, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zgtts2_(integer *itrans, integer *n, integer *nrhs, 
	doublecomplex *dl, doublecomplex *d__, doublecomplex *du, 
	doublecomplex *du2, integer *ipiv, doublecomplex *b, integer *ldb);
 
/* Subroutine */ extern "C" int zhbev_(char *jobz, char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, doublereal *w, doublecomplex *z__, 
	integer *ldz, doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zhbevd_(char *jobz, char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, doublereal *w, doublecomplex *z__, 
	integer *ldz, doublecomplex *work, integer *lwork, doublereal *rwork, 
	integer *lrwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int zhbevx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *kd, doublecomplex *ab, integer *ldab, doublecomplex *q, 
	integer *ldq, doublereal *vl, doublereal *vu, integer *il, integer *
	iu, doublereal *abstol, integer *m, doublereal *w, doublecomplex *z__,
	 integer *ldz, doublecomplex *work, doublereal *rwork, integer *iwork,
	 integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int zhbgst_(char *vect, char *uplo, integer *n, integer *ka, 
	integer *kb, doublecomplex *ab, integer *ldab, doublecomplex *bb, 
	integer *ldbb, doublecomplex *x, integer *ldx, doublecomplex *work, 
	doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zhbgv_(char *jobz, char *uplo, integer *n, integer *ka, 
	integer *kb, doublecomplex *ab, integer *ldab, doublecomplex *bb, 
	integer *ldbb, doublereal *w, doublecomplex *z__, integer *ldz, 
	doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zhbgvx_(char *jobz, char *range, char *uplo, integer *n, 
	integer *ka, integer *kb, doublecomplex *ab, integer *ldab, 
	doublecomplex *bb, integer *ldbb, doublecomplex *q, integer *ldq, 
	doublereal *vl, doublereal *vu, integer *il, integer *iu, doublereal *
	abstol, integer *m, doublereal *w, doublecomplex *z__, integer *ldz, 
	doublecomplex *work, doublereal *rwork, integer *iwork, integer *
	ifail, integer *info);
 
/* Subroutine */ extern "C" int zhbtrd_(char *vect, char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, doublereal *d__, doublereal *e, 
	doublecomplex *q, integer *ldq, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zhecon_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, doublereal *anorm, doublereal *rcond, 
	doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zheev_(char *jobz, char *uplo, integer *n, doublecomplex 
	*a, integer *lda, doublereal *w, doublecomplex *work, integer *lwork, 
	doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zheevd_(char *jobz, char *uplo, integer *n, 
	doublecomplex *a, integer *lda, doublereal *w, doublecomplex *work, 
	integer *lwork, doublereal *rwork, integer *lrwork, integer *iwork, 
	integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int zheevr_(char *jobz, char *range, char *uplo, integer *n, 
	doublecomplex *a, integer *lda, doublereal *vl, doublereal *vu, 
	integer *il, integer *iu, doublereal *abstol, integer *m, doublereal *
	w, doublecomplex *z__, integer *ldz, integer *isuppz, doublecomplex *
	work, integer *lwork, doublereal *rwork, integer *lrwork, integer *
	iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int zheevx_(char *jobz, char *range, char *uplo, integer *n, 
	doublecomplex *a, integer *lda, doublereal *vl, doublereal *vu, 
	integer *il, integer *iu, doublereal *abstol, integer *m, doublereal *
	w, doublecomplex *z__, integer *ldz, doublecomplex *work, integer *
	lwork, doublereal *rwork, integer *iwork, integer *ifail, integer *
	info);
 
/* Subroutine */ extern "C" int zhegs2_(integer *itype, char *uplo, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zhegst_(integer *itype, char *uplo, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zhegv_(integer *itype, char *jobz, char *uplo, integer *
	n, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublereal *w, doublecomplex *work, integer *lwork, doublereal *rwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zhegvd_(integer *itype, char *jobz, char *uplo, integer *
	n, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublereal *w, doublecomplex *work, integer *lwork, doublereal *rwork,
	 integer *lrwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int zhegvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, doublecomplex *a, integer *lda, doublecomplex *b, 
	integer *ldb, doublereal *vl, doublereal *vu, integer *il, integer *
	iu, doublereal *abstol, integer *m, doublereal *w, doublecomplex *z__,
	 integer *ldz, doublecomplex *work, integer *lwork, doublereal *rwork,
	 integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int zherfs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, doublecomplex *af, integer *ldaf, 
	integer *ipiv, doublecomplex *b, integer *ldb, doublecomplex *x, 
	integer *ldx, doublereal *ferr, doublereal *berr, doublecomplex *work,
	 doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zhesv_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, integer *ipiv, doublecomplex *b, 
	integer *ldb, doublecomplex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zhesvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublecomplex *a, integer *lda, doublecomplex *af, integer *
	ldaf, integer *ipiv, doublecomplex *b, integer *ldb, doublecomplex *x,
	 integer *ldx, doublereal *rcond, doublereal *ferr, doublereal *berr, 
	doublecomplex *work, integer *lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zhetf2_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int zhetrd_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, doublereal *d__, doublereal *e, doublecomplex *tau, 
	doublecomplex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zhetrf_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, doublecomplex *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int zhetri_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zhetrs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, integer *ipiv, doublecomplex *b, 
	integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int zhgeqz_(char *job, char *compq, char *compz, integer *n, 
	integer *ilo, integer *ihi, doublecomplex *a, integer *lda, 
	doublecomplex *b, integer *ldb, doublecomplex *alpha, doublecomplex *
	beta, doublecomplex *q, integer *ldq, doublecomplex *z__, integer *
	ldz, doublecomplex *work, integer *lwork, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zhpcon_(char *uplo, integer *n, doublecomplex *ap, 
	integer *ipiv, doublereal *anorm, doublereal *rcond, doublecomplex *
	work, integer *info);
 
/* Subroutine */ extern "C" int zhpev_(char *jobz, char *uplo, integer *n, doublecomplex 
	*ap, doublereal *w, doublecomplex *z__, integer *ldz, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zhpevd_(char *jobz, char *uplo, integer *n, 
	doublecomplex *ap, doublereal *w, doublecomplex *z__, integer *ldz, 
	doublecomplex *work, integer *lwork, doublereal *rwork, integer *
	lrwork, integer *iwork, integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int zhpevx_(char *jobz, char *range, char *uplo, integer *n, 
	doublecomplex *ap, doublereal *vl, doublereal *vu, integer *il, 
	integer *iu, doublereal *abstol, integer *m, doublereal *w, 
	doublecomplex *z__, integer *ldz, doublecomplex *work, doublereal *
	rwork, integer *iwork, integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int zhpgst_(integer *itype, char *uplo, integer *n, 
	doublecomplex *ap, doublecomplex *bp, integer *info);
 
/* Subroutine */ extern "C" int zhpgv_(integer *itype, char *jobz, char *uplo, integer *
	n, doublecomplex *ap, doublecomplex *bp, doublereal *w, doublecomplex 
	*z__, integer *ldz, doublecomplex *work, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zhpgvd_(integer *itype, char *jobz, char *uplo, integer *
	n, doublecomplex *ap, doublecomplex *bp, doublereal *w, doublecomplex 
	*z__, integer *ldz, doublecomplex *work, integer *lwork, doublereal *
	rwork, integer *lrwork, integer *iwork, integer *liwork, integer *
	info);
 
/* Subroutine */ extern "C" int zhpgvx_(integer *itype, char *jobz, char *range, char *
	uplo, integer *n, doublecomplex *ap, doublecomplex *bp, doublereal *
	vl, doublereal *vu, integer *il, integer *iu, doublereal *abstol, 
	integer *m, doublereal *w, doublecomplex *z__, integer *ldz, 
	doublecomplex *work, doublereal *rwork, integer *iwork, integer *
	ifail, integer *info);
 
/* Subroutine */ extern "C" int zhprfs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, doublecomplex *afp, integer *ipiv, doublecomplex *
	b, integer *ldb, doublecomplex *x, integer *ldx, doublereal *ferr, 
	doublereal *berr, doublecomplex *work, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zhpsv_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, integer *ipiv, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zhpsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublecomplex *ap, doublecomplex *afp, integer *ipiv, 
	doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx, 
	doublereal *rcond, doublereal *ferr, doublereal *berr, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zhptrd_(char *uplo, integer *n, doublecomplex *ap, 
	doublereal *d__, doublereal *e, doublecomplex *tau, integer *info);
 
/* Subroutine */ extern "C" int zhptrf_(char *uplo, integer *n, doublecomplex *ap, 
	integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int zhptri_(char *uplo, integer *n, doublecomplex *ap, 
	integer *ipiv, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zhptrs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, integer *ipiv, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zhsein_(char *side, char *eigsrc, char *initv, logical *
	select, integer *n, doublecomplex *h__, integer *ldh, doublecomplex *
	w, doublecomplex *vl, integer *ldvl, doublecomplex *vr, integer *ldvr,
	 integer *mm, integer *m, doublecomplex *work, doublereal *rwork, 
	integer *ifaill, integer *ifailr, integer *info);
 
/* Subroutine */ extern "C" int zhseqr_(char *job, char *compz, integer *n, integer *ilo,
	 integer *ihi, doublecomplex *h__, integer *ldh, doublecomplex *w, 
	doublecomplex *z__, integer *ldz, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zlabrd_(integer *m, integer *n, integer *nb, 
	doublecomplex *a, integer *lda, doublereal *d__, doublereal *e, 
	doublecomplex *tauq, doublecomplex *taup, doublecomplex *x, integer *
	ldx, doublecomplex *y, integer *ldy);
 
/* Subroutine */ extern "C" int zlacgv_(integer *n, doublecomplex *x, integer *incx);
 
/* Subroutine */ extern "C" int zlacon_(integer *n, doublecomplex *v, doublecomplex *x, 
	doublereal *est, integer *kase);
 
/* Subroutine */ extern "C" int zlacp2_(char *uplo, integer *m, integer *n, doublereal *
	a, integer *lda, doublecomplex *b, integer *ldb);
 
/* Subroutine */ extern "C" int zlacpy_(char *uplo, integer *m, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb);
 
/* Subroutine */ extern "C" int zlacrm_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublereal *b, integer *ldb, doublecomplex *c__, 
	integer *ldc, doublereal *rwork);
 
/* Subroutine */ extern "C" int zlacrt_(integer *n, doublecomplex *cx, integer *incx, 
	doublecomplex *cy, integer *incy, doublecomplex *c__, doublecomplex *
	s);
 
/* Subroutine */ extern "C" int zlaed0_(integer *qsiz, integer *n, doublereal *d__, 
	doublereal *e, doublecomplex *q, integer *ldq, doublecomplex *qstore, 
	integer *ldqs, doublereal *rwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int zlaed7_(integer *n, integer *cutpnt, integer *qsiz, 
	integer *tlvls, integer *curlvl, integer *curpbm, doublereal *d__, 
	doublecomplex *q, integer *ldq, doublereal *rho, integer *indxq, 
	doublereal *qstore, integer *qptr, integer *prmptr, integer *perm, 
	integer *givptr, integer *givcol, doublereal *givnum, doublecomplex *
	work, doublereal *rwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int zlaed8_(integer *k, integer *n, integer *qsiz, 
	doublecomplex *q, integer *ldq, doublereal *d__, doublereal *rho, 
	integer *cutpnt, doublereal *z__, doublereal *dlamda, doublecomplex *
	q2, integer *ldq2, doublereal *w, integer *indxp, integer *indx, 
	integer *indxq, integer *perm, integer *givptr, integer *givcol, 
	doublereal *givnum, integer *info);
 
/* Subroutine */ extern "C" int zlaein_(logical *rightv, logical *noinit, integer *n, 
	doublecomplex *h__, integer *ldh, doublecomplex *w, doublecomplex *v, 
	doublecomplex *b, integer *ldb, doublereal *rwork, doublereal *eps3, 
	doublereal *smlnum, integer *info);
 
/* Subroutine */ extern "C" int zlaesy_(doublecomplex *a, doublecomplex *b, 
	doublecomplex *c__, doublecomplex *rt1, doublecomplex *rt2, 
	doublecomplex *evscal, doublecomplex *cs1, doublecomplex *sn1);
 
/* Subroutine */ extern "C" int zlaev2_(doublecomplex *a, doublecomplex *b, 
	doublecomplex *c__, doublereal *rt1, doublereal *rt2, doublereal *cs1,
	 doublecomplex *sn1);
 
/* Subroutine */ extern "C" int zlags2_(logical *upper, doublereal *a1, doublecomplex *
	a2, doublereal *a3, doublereal *b1, doublecomplex *b2, doublereal *b3,
	 doublereal *csu, doublecomplex *snu, doublereal *csv, doublecomplex *
	snv, doublereal *csq, doublecomplex *snq);
 
/* Subroutine */ extern "C" int zlagtm_(char *trans, integer *n, integer *nrhs, 
	doublereal *alpha, doublecomplex *dl, doublecomplex *d__, 
	doublecomplex *du, doublecomplex *x, integer *ldx, doublereal *beta, 
	doublecomplex *b, integer *ldb);
 
/* Subroutine */ extern "C" int zlahef_(char *uplo, integer *n, integer *nb, integer *kb,
	 doublecomplex *a, integer *lda, integer *ipiv, doublecomplex *w, 
	integer *ldw, integer *info);
 
/* Subroutine */ extern "C" int zlahqr_(logical *wantt, logical *wantz, integer *n, 
	integer *ilo, integer *ihi, doublecomplex *h__, integer *ldh, 
	doublecomplex *w, integer *iloz, integer *ihiz, doublecomplex *z__, 
	integer *ldz, integer *info);
 
/* Subroutine */ extern "C" int zlahrd_(integer *n, integer *k, integer *nb, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *t, 
	integer *ldt, doublecomplex *y, integer *ldy);
 
/* Subroutine */ extern "C" int zlaic1_(integer *job, integer *j, doublecomplex *x, 
	doublereal *sest, doublecomplex *w, doublecomplex *gamma, doublereal *
	sestpr, doublecomplex *s, doublecomplex *c__);
 
/* Subroutine */ extern "C" int zlals0_(integer *icompq, integer *nl, integer *nr, 
	integer *sqre, integer *nrhs, doublecomplex *b, integer *ldb, 
	doublecomplex *bx, integer *ldbx, integer *perm, integer *givptr, 
	integer *givcol, integer *ldgcol, doublereal *givnum, integer *ldgnum,
	 doublereal *poles, doublereal *difl, doublereal *difr, doublereal *
	z__, integer *k, doublereal *c__, doublereal *s, doublereal *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int zlalsa_(integer *icompq, integer *smlsiz, integer *n, 
	integer *nrhs, doublecomplex *b, integer *ldb, doublecomplex *bx, 
	integer *ldbx, doublereal *u, integer *ldu, doublereal *vt, integer *
	k, doublereal *difl, doublereal *difr, doublereal *z__, doublereal *
	poles, integer *givptr, integer *givcol, integer *ldgcol, integer *
	perm, doublereal *givnum, doublereal *c__, doublereal *s, doublereal *
	rwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int zlapll_(integer *n, doublecomplex *x, integer *incx, 
	doublecomplex *y, integer *incy, doublereal *ssmin);
 
/* Subroutine */ extern "C" int zlapmt_(logical *forwrd, integer *m, integer *n, 
	doublecomplex *x, integer *ldx, integer *k);
 
/* Subroutine */ extern "C" int zlaqgb_(integer *m, integer *n, integer *kl, integer *ku,
	 doublecomplex *ab, integer *ldab, doublereal *r__, doublereal *c__, 
	doublereal *rowcnd, doublereal *colcnd, doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int zlaqge_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublereal *r__, doublereal *c__, doublereal *rowcnd, 
	doublereal *colcnd, doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int zlaqhb_(char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, doublereal *s, doublereal *scond, 
	doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int zlaqhe_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, doublereal *s, doublereal *scond, doublereal *amax, 
	char *equed);
 
/* Subroutine */ extern "C" int zlaqhp_(char *uplo, integer *n, doublecomplex *ap, 
	doublereal *s, doublereal *scond, doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int zlaqp2_(integer *m, integer *n, integer *offset, 
	doublecomplex *a, integer *lda, integer *jpvt, doublecomplex *tau, 
	doublereal *vn1, doublereal *vn2, doublecomplex *work);
 
/* Subroutine */ extern "C" int zlaqps_(integer *m, integer *n, integer *offset, integer 
	*nb, integer *kb, doublecomplex *a, integer *lda, integer *jpvt, 
	doublecomplex *tau, doublereal *vn1, doublereal *vn2, doublecomplex *
	auxv, doublecomplex *f, integer *ldf);
 
/* Subroutine */ extern "C" int zlaqsb_(char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, doublereal *s, doublereal *scond, 
	doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int zlaqsp_(char *uplo, integer *n, doublecomplex *ap, 
	doublereal *s, doublereal *scond, doublereal *amax, char *equed);
 
/* Subroutine */ extern "C" int zlaqsy_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, doublereal *s, doublereal *scond, doublereal *amax, 
	char *equed);
 
/* Subroutine */ extern "C" int zlar1v_(integer *n, integer *b1, integer *bn, doublereal 
	*sigma, doublereal *d__, doublereal *l, doublereal *ld, doublereal *
	lld, doublereal *gersch, doublecomplex *z__, doublereal *ztz, 
	doublereal *mingma, integer *r__, integer *isuppz, doublereal *work);
 
/* Subroutine */ extern "C" int zlar2v_(integer *n, doublecomplex *x, doublecomplex *y, 
	doublecomplex *z__, integer *incx, doublereal *c__, doublecomplex *s, 
	integer *incc);
 
/* Subroutine */ extern "C" int zlarcm_(integer *m, integer *n, doublereal *a, integer *
	lda, doublecomplex *b, integer *ldb, doublecomplex *c__, integer *ldc,
	 doublereal *rwork);
 
/* Subroutine */ extern "C" int zlarf_(char *side, integer *m, integer *n, doublecomplex 
	*v, integer *incv, doublecomplex *tau, doublecomplex *c__, integer *
	ldc, doublecomplex *work);
 
/* Subroutine */ extern "C" int zlarfb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, doublecomplex *v, integer 
	*ldv, doublecomplex *t, integer *ldt, doublecomplex *c__, integer *
	ldc, doublecomplex *work, integer *ldwork);
 
/* Subroutine */ extern "C" int zlarfg_(integer *n, doublecomplex *alpha, doublecomplex *
	x, integer *incx, doublecomplex *tau);
 
/* Subroutine */ extern "C" int zlarft_(char *direct, char *storev, integer *n, integer *
	k, doublecomplex *v, integer *ldv, doublecomplex *tau, doublecomplex *
	t, integer *ldt);
 
/* Subroutine */ extern "C" int zlarfx_(char *side, integer *m, integer *n, 
	doublecomplex *v, doublecomplex *tau, doublecomplex *c__, integer *
	ldc, doublecomplex *work);
 
/* Subroutine */ extern "C" int zlargv_(integer *n, doublecomplex *x, integer *incx, 
	doublecomplex *y, integer *incy, doublereal *c__, integer *incc);
 
/* Subroutine */ extern "C" int zlarnv_(integer *idist, integer *iseed, integer *n, 
	doublecomplex *x);
 
/* Subroutine */ extern "C" int zlarrv_(integer *n, doublereal *d__, doublereal *l, 
	integer *isplit, integer *m, doublereal *w, integer *iblock, 
	doublereal *gersch, doublereal *tol, doublecomplex *z__, integer *ldz,
	 integer *isuppz, doublereal *work, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int zlartg_(doublecomplex *f, doublecomplex *g, doublereal *
	cs, doublecomplex *sn, doublecomplex *r__);
 
/* Subroutine */ extern "C" int zlartv_(integer *n, doublecomplex *x, integer *incx, 
	doublecomplex *y, integer *incy, doublereal *c__, doublecomplex *s, 
	integer *incc);
 
/* Subroutine */ extern "C" int zlarz_(char *side, integer *m, integer *n, integer *l, 
	doublecomplex *v, integer *incv, doublecomplex *tau, doublecomplex *
	c__, integer *ldc, doublecomplex *work);
 
/* Subroutine */ extern "C" int zlarzb_(char *side, char *trans, char *direct, char *
	storev, integer *m, integer *n, integer *k, integer *l, doublecomplex 
	*v, integer *ldv, doublecomplex *t, integer *ldt, doublecomplex *c__, 
	integer *ldc, doublecomplex *work, integer *ldwork);
 
/* Subroutine */ extern "C" int zlarzt_(char *direct, char *storev, integer *n, integer *
	k, doublecomplex *v, integer *ldv, doublecomplex *tau, doublecomplex *
	t, integer *ldt);
 
/* Subroutine */ extern "C" int zlascl_(char *type__, integer *kl, integer *ku, 
	doublereal *cfrom, doublereal *cto, integer *m, integer *n, 
	doublecomplex *a, integer *lda, integer *info);
 
/* Subroutine */ extern "C" int zlaset_(char *uplo, integer *m, integer *n, 
	doublecomplex *alpha, doublecomplex *beta, doublecomplex *a, integer *
	lda);
 
/* Subroutine */ extern "C" int zlasr_(char *side, char *pivot, char *direct, integer *m,
	 integer *n, doublereal *c__, doublereal *s, doublecomplex *a, 
	integer *lda);
 
/* Subroutine */ extern "C" int zlassq_(integer *n, doublecomplex *x, integer *incx, 
	doublereal *scale, doublereal *sumsq);
 
/* Subroutine */ extern "C" int zlaswp_(integer *n, doublecomplex *a, integer *lda, 
	integer *k1, integer *k2, integer *ipiv, integer *incx);
 
/* Subroutine */ extern "C" int zlasyf_(char *uplo, integer *n, integer *nb, integer *kb,
	 doublecomplex *a, integer *lda, integer *ipiv, doublecomplex *w, 
	integer *ldw, integer *info);
 
/* Subroutine */ extern "C" int zlatbs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, integer *kd, doublecomplex *ab, integer *ldab, 
	doublecomplex *x, doublereal *scale, doublereal *cnorm, integer *info);
 
/* Subroutine */ extern "C" int zlatdf_(integer *ijob, integer *n, doublecomplex *z__, 
	integer *ldz, doublecomplex *rhs, doublereal *rdsum, doublereal *
	rdscal, integer *ipiv, integer *jpiv);
 
/* Subroutine */ extern "C" int zlatps_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, doublecomplex *ap, doublecomplex *x, doublereal *
	scale, doublereal *cnorm, integer *info);
 
/* Subroutine */ extern "C" int zlatrd_(char *uplo, integer *n, integer *nb, 
	doublecomplex *a, integer *lda, doublereal *e, doublecomplex *tau, 
	doublecomplex *w, integer *ldw);
 
/* Subroutine */ extern "C" int zlatrs_(char *uplo, char *trans, char *diag, char *
	normin, integer *n, doublecomplex *a, integer *lda, doublecomplex *x, 
	doublereal *scale, doublereal *cnorm, integer *info);
 
/* Subroutine */ extern "C" int zlatrz_(integer *m, integer *n, integer *l, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work);
 
/* Subroutine */ extern "C" int zlatzm_(char *side, integer *m, integer *n, 
	doublecomplex *v, integer *incv, doublecomplex *tau, doublecomplex *
	c1, doublecomplex *c2, integer *ldc, doublecomplex *work);
 
/* Subroutine */ extern "C" int zlauu2_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int zlauum_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int zpbcon_(char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, doublereal *anorm, doublereal *
	rcond, doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zpbequ_(char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, doublereal *s, doublereal *scond, 
	doublereal *amax, integer *info);
 
/* Subroutine */ extern "C" int zpbrfs_(char *uplo, integer *n, integer *kd, integer *
	nrhs, doublecomplex *ab, integer *ldab, doublecomplex *afb, integer *
	ldafb, doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx,
	 doublereal *ferr, doublereal *berr, doublecomplex *work, doublereal *
	rwork, integer *info);
 
/* Subroutine */ extern "C" int zpbstf_(char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int zpbsv_(char *uplo, integer *n, integer *kd, integer *
	nrhs, doublecomplex *ab, integer *ldab, doublecomplex *b, integer *
	ldb, integer *info);
 
/* Subroutine */ extern "C" int zpbsvx_(char *fact, char *uplo, integer *n, integer *kd, 
	integer *nrhs, doublecomplex *ab, integer *ldab, doublecomplex *afb, 
	integer *ldafb, char *equed, doublereal *s, doublecomplex *b, integer 
	*ldb, doublecomplex *x, integer *ldx, doublereal *rcond, doublereal *
	ferr, doublereal *berr, doublecomplex *work, doublereal *rwork, 
	integer *info);
 
/* Subroutine */ extern "C" int zpbtf2_(char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int zpbtrf_(char *uplo, integer *n, integer *kd, 
	doublecomplex *ab, integer *ldab, integer *info);
 
/* Subroutine */ extern "C" int zpbtrs_(char *uplo, integer *n, integer *kd, integer *
	nrhs, doublecomplex *ab, integer *ldab, doublecomplex *b, integer *
	ldb, integer *info);
 
/* Subroutine */ extern "C" int zpocon_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, doublereal *anorm, doublereal *rcond, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zpoequ_(integer *n, doublecomplex *a, integer *lda, 
	doublereal *s, doublereal *scond, doublereal *amax, integer *info);
 
/* Subroutine */ extern "C" int zporfs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, doublecomplex *af, integer *ldaf, 
	doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx, 
	doublereal *ferr, doublereal *berr, doublecomplex *work, doublereal *
	rwork, integer *info);
 
/* Subroutine */ extern "C" int zposv_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zposvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublecomplex *a, integer *lda, doublecomplex *af, integer *
	ldaf, char *equed, doublereal *s, doublecomplex *b, integer *ldb, 
	doublecomplex *x, integer *ldx, doublereal *rcond, doublereal *ferr, 
	doublereal *berr, doublecomplex *work, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zpotf2_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int zpotrf_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int zpotri_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *info);
 
/* Subroutine */ extern "C" int zpotrs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zppcon_(char *uplo, integer *n, doublecomplex *ap, 
	doublereal *anorm, doublereal *rcond, doublecomplex *work, doublereal 
	*rwork, integer *info);
 
/* Subroutine */ extern "C" int zppequ_(char *uplo, integer *n, doublecomplex *ap, 
	doublereal *s, doublereal *scond, doublereal *amax, integer *info);
 
/* Subroutine */ extern "C" int zpprfs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, doublecomplex *afp, doublecomplex *b, integer *ldb,
	 doublecomplex *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zppsv_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, doublecomplex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int zppsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublecomplex *ap, doublecomplex *afp, char *equed, doublereal *
	s, doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx, 
	doublereal *rcond, doublereal *ferr, doublereal *berr, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zpptrf_(char *uplo, integer *n, doublecomplex *ap, 
	integer *info);
 
/* Subroutine */ extern "C" int zpptri_(char *uplo, integer *n, doublecomplex *ap, 
	integer *info);
 
/* Subroutine */ extern "C" int zpptrs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, doublecomplex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int zptcon_(integer *n, doublereal *d__, doublecomplex *e, 
	doublereal *anorm, doublereal *rcond, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zptrfs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *d__, doublecomplex *e, doublereal *df, doublecomplex *ef, 
	doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx, 
	doublereal *ferr, doublereal *berr, doublecomplex *work, doublereal *
	rwork, integer *info);
 
/* Subroutine */ extern "C" int zptsv_(integer *n, integer *nrhs, doublereal *d__, 
	doublecomplex *e, doublecomplex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int zptsvx_(char *fact, integer *n, integer *nrhs, 
	doublereal *d__, doublecomplex *e, doublereal *df, doublecomplex *ef, 
	doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx, 
	doublereal *rcond, doublereal *ferr, doublereal *berr, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zpttrf_(integer *n, doublereal *d__, doublecomplex *e, 
	integer *info);
 
/* Subroutine */ extern "C" int zpttrs_(char *uplo, integer *n, integer *nrhs, 
	doublereal *d__, doublecomplex *e, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zptts2_(integer *iuplo, integer *n, integer *nrhs, 
	doublereal *d__, doublecomplex *e, doublecomplex *b, integer *ldb);
 
/* Subroutine */ extern "C" int zrot_(integer *n, doublecomplex *cx, integer *incx, 
	doublecomplex *cy, integer *incy, doublereal *c__, doublecomplex *s);
 
/* Subroutine */ extern "C" int zspcon_(char *uplo, integer *n, doublecomplex *ap, 
	integer *ipiv, doublereal *anorm, doublereal *rcond, doublecomplex *
	work, integer *info);
 
/* Subroutine */ extern "C" int zspmv_(char *uplo, integer *n, doublecomplex *alpha, 
	doublecomplex *ap, doublecomplex *x, integer *incx, doublecomplex *
	beta, doublecomplex *y, integer *incy);
 
/* Subroutine */ extern "C" int zspr_(char *uplo, integer *n, doublecomplex *alpha, 
	doublecomplex *x, integer *incx, doublecomplex *ap);
 
/* Subroutine */ extern "C" int zsprfs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, doublecomplex *afp, integer *ipiv, doublecomplex *
	b, integer *ldb, doublecomplex *x, integer *ldx, doublereal *ferr, 
	doublereal *berr, doublecomplex *work, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int zspsv_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, integer *ipiv, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zspsvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublecomplex *ap, doublecomplex *afp, integer *ipiv, 
	doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx, 
	doublereal *rcond, doublereal *ferr, doublereal *berr, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zsptrf_(char *uplo, integer *n, doublecomplex *ap, 
	integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int zsptri_(char *uplo, integer *n, doublecomplex *ap, 
	integer *ipiv, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zsptrs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *ap, integer *ipiv, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int zstedc_(char *compz, integer *n, doublereal *d__, 
	doublereal *e, doublecomplex *z__, integer *ldz, doublecomplex *work, 
	integer *lwork, doublereal *rwork, integer *lrwork, integer *iwork, 
	integer *liwork, integer *info);
 
/* Subroutine */ extern "C" int zstein_(integer *n, doublereal *d__, doublereal *e, 
	integer *m, doublereal *w, integer *iblock, integer *isplit, 
	doublecomplex *z__, integer *ldz, doublereal *work, integer *iwork, 
	integer *ifail, integer *info);
 
/* Subroutine */ extern "C" int zsteqr_(char *compz, integer *n, doublereal *d__, 
	doublereal *e, doublecomplex *z__, integer *ldz, doublereal *work, 
	integer *info);
 
/* Subroutine */ extern "C" int zsycon_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, doublereal *anorm, doublereal *rcond, 
	doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zsymv_(char *uplo, integer *n, doublecomplex *alpha, 
	doublecomplex *a, integer *lda, doublecomplex *x, integer *incx, 
	doublecomplex *beta, doublecomplex *y, integer *incy);
 
/* Subroutine */ extern "C" int zsyr_(char *uplo, integer *n, doublecomplex *alpha, 
	doublecomplex *x, integer *incx, doublecomplex *a, integer *lda);
 
/* Subroutine */ extern "C" int zsyrfs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, doublecomplex *af, integer *ldaf, 
	integer *ipiv, doublecomplex *b, integer *ldb, doublecomplex *x, 
	integer *ldx, doublereal *ferr, doublereal *berr, doublecomplex *work,
	 doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zsysv_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, integer *ipiv, doublecomplex *b, 
	integer *ldb, doublecomplex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zsysvx_(char *fact, char *uplo, integer *n, integer *
	nrhs, doublecomplex *a, integer *lda, doublecomplex *af, integer *
	ldaf, integer *ipiv, doublecomplex *b, integer *ldb, doublecomplex *x,
	 integer *ldx, doublereal *rcond, doublereal *ferr, doublereal *berr, 
	doublecomplex *work, integer *lwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int zsytf2_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, integer *info);
 
/* Subroutine */ extern "C" int zsytrf_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, doublecomplex *work, integer *lwork, 
	integer *info);
 
/* Subroutine */ extern "C" int zsytri_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, integer *ipiv, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zsytrs_(char *uplo, integer *n, integer *nrhs, 
	doublecomplex *a, integer *lda, integer *ipiv, doublecomplex *b, 
	integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int ztbcon_(char *norm, char *uplo, char *diag, integer *n, 
	integer *kd, doublecomplex *ab, integer *ldab, doublereal *rcond, 
	doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int ztbrfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *kd, integer *nrhs, doublecomplex *ab, integer *ldab, 
	doublecomplex *b, integer *ldb, doublecomplex *x, integer *ldx, 
	doublereal *ferr, doublereal *berr, doublecomplex *work, doublereal *
	rwork, integer *info);
 
/* Subroutine */ extern "C" int ztbtrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *kd, integer *nrhs, doublecomplex *ab, integer *ldab, 
	doublecomplex *b, integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int ztgevc_(char *side, char *howmny, logical *select, 
	integer *n, doublecomplex *a, integer *lda, doublecomplex *b, integer 
	*ldb, doublecomplex *vl, integer *ldvl, doublecomplex *vr, integer *
	ldvr, integer *mm, integer *m, doublecomplex *work, doublereal *rwork,
	 integer *info);
 
/* Subroutine */ extern "C" int ztgex2_(logical *wantq, logical *wantz, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *q, integer *ldq, doublecomplex *z__, integer *ldz, 
	integer *j1, integer *info);
 
/* Subroutine */ extern "C" int ztgexc_(logical *wantq, logical *wantz, integer *n, 
	doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *q, integer *ldq, doublecomplex *z__, integer *ldz, 
	integer *ifst, integer *ilst, integer *info);
 
/* Subroutine */ extern "C" int ztgsen_(integer *ijob, logical *wantq, logical *wantz, 
	logical *select, integer *n, doublecomplex *a, integer *lda, 
	doublecomplex *b, integer *ldb, doublecomplex *alpha, doublecomplex *
	beta, doublecomplex *q, integer *ldq, doublecomplex *z__, integer *
	ldz, integer *m, doublereal *pl, doublereal *pr, doublereal *dif, 
	doublecomplex *work, integer *lwork, integer *iwork, integer *liwork, 
	integer *info);
 
/* Subroutine */ extern "C" int ztgsja_(char *jobu, char *jobv, char *jobq, integer *m, 
	integer *p, integer *n, integer *k, integer *l, doublecomplex *a, 
	integer *lda, doublecomplex *b, integer *ldb, doublereal *tola, 
	doublereal *tolb, doublereal *alpha, doublereal *beta, doublecomplex *
	u, integer *ldu, doublecomplex *v, integer *ldv, doublecomplex *q, 
	integer *ldq, doublecomplex *work, integer *ncycle, integer *info);
 
/* Subroutine */ extern "C" int ztgsna_(char *job, char *howmny, logical *select, 
	integer *n, doublecomplex *a, integer *lda, doublecomplex *b, integer 
	*ldb, doublecomplex *vl, integer *ldvl, doublecomplex *vr, integer *
	ldvr, doublereal *s, doublereal *dif, integer *mm, integer *m, 
	doublecomplex *work, integer *lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int ztgsy2_(char *trans, integer *ijob, integer *m, integer *
	n, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *c__, integer *ldc, doublecomplex *d__, integer *ldd, 
	doublecomplex *e, integer *lde, doublecomplex *f, integer *ldf, 
	doublereal *scale, doublereal *rdsum, doublereal *rdscal, integer *
	info);
 
/* Subroutine */ extern "C" int ztgsyl_(char *trans, integer *ijob, integer *m, integer *
	n, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, 
	doublecomplex *c__, integer *ldc, doublecomplex *d__, integer *ldd, 
	doublecomplex *e, integer *lde, doublecomplex *f, integer *ldf, 
	doublereal *scale, doublereal *dif, doublecomplex *work, integer *
	lwork, integer *iwork, integer *info);
 
/* Subroutine */ extern "C" int ztpcon_(char *norm, char *uplo, char *diag, integer *n, 
	doublecomplex *ap, doublereal *rcond, doublecomplex *work, doublereal 
	*rwork, integer *info);
 
/* Subroutine */ extern "C" int ztprfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublecomplex *ap, doublecomplex *b, integer *ldb, 
	doublecomplex *x, integer *ldx, doublereal *ferr, doublereal *berr, 
	doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int ztptri_(char *uplo, char *diag, integer *n, 
	doublecomplex *ap, integer *info);
 
/* Subroutine */ extern "C" int ztptrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublecomplex *ap, doublecomplex *b, integer *ldb, 
	integer *info);
 
/* Subroutine */ extern "C" int ztrcon_(char *norm, char *uplo, char *diag, integer *n, 
	doublecomplex *a, integer *lda, doublereal *rcond, doublecomplex *
	work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int ztrevc_(char *side, char *howmny, logical *select, 
	integer *n, doublecomplex *t, integer *ldt, doublecomplex *vl, 
	integer *ldvl, doublecomplex *vr, integer *ldvr, integer *mm, integer 
	*m, doublecomplex *work, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int ztrexc_(char *compq, integer *n, doublecomplex *t, 
	integer *ldt, doublecomplex *q, integer *ldq, integer *ifst, integer *
	ilst, integer *info);
 
/* Subroutine */ extern "C" int ztrrfs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublecomplex *a, integer *lda, doublecomplex *b, 
	integer *ldb, doublecomplex *x, integer *ldx, doublereal *ferr, 
	doublereal *berr, doublecomplex *work, doublereal *rwork, integer *
	info);
 
/* Subroutine */ extern "C" int ztrsen_(char *job, char *compq, logical *select, integer 
	*n, doublecomplex *t, integer *ldt, doublecomplex *q, integer *ldq, 
	doublecomplex *w, integer *m, doublereal *s, doublereal *sep, 
	doublecomplex *work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int ztrsna_(char *job, char *howmny, logical *select, 
	integer *n, doublecomplex *t, integer *ldt, doublecomplex *vl, 
	integer *ldvl, doublecomplex *vr, integer *ldvr, doublereal *s, 
	doublereal *sep, integer *mm, integer *m, doublecomplex *work, 
	integer *ldwork, doublereal *rwork, integer *info);
 
/* Subroutine */ extern "C" int ztrsyl_(char *trana, char *tranb, integer *isgn, integer 
	*m, integer *n, doublecomplex *a, integer *lda, doublecomplex *b, 
	integer *ldb, doublecomplex *c__, integer *ldc, doublereal *scale, 
	integer *info);
 
/* Subroutine */ extern "C" int ztrti2_(char *uplo, char *diag, integer *n, 
	doublecomplex *a, integer *lda, integer *info);
 
/* Subroutine */ extern "C" int ztrtri_(char *uplo, char *diag, integer *n, 
	doublecomplex *a, integer *lda, integer *info);
 
/* Subroutine */ extern "C" int ztrtrs_(char *uplo, char *trans, char *diag, integer *n, 
	integer *nrhs, doublecomplex *a, integer *lda, doublecomplex *b, 
	integer *ldb, integer *info);
 
/* Subroutine */ extern "C" int ztzrqf_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, integer *info);
 
/* Subroutine */ extern "C" int ztzrzf_(integer *m, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zung2l_(integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *info);
 
/* Subroutine */ extern "C" int zung2r_(integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *info);
 
/* Subroutine */ extern "C" int zungbr_(char *vect, integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zunghr_(integer *n, integer *ilo, integer *ihi, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zungl2_(integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *info);
 
/* Subroutine */ extern "C" int zunglq_(integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zungql_(integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zungqr_(integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zungr2_(integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *info);
 
/* Subroutine */ extern "C" int zungrq_(integer *m, integer *n, integer *k, 
	doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zungtr_(char *uplo, integer *n, doublecomplex *a, 
	integer *lda, doublecomplex *tau, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zunm2l_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zunm2r_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zunmbr_(char *vect, char *side, char *trans, integer *m, 
	integer *n, integer *k, doublecomplex *a, integer *lda, doublecomplex 
	*tau, doublecomplex *c__, integer *ldc, doublecomplex *work, integer *
	lwork, integer *info);
 
/* Subroutine */ extern "C" int zunmhr_(char *side, char *trans, integer *m, integer *n, 
	integer *ilo, integer *ihi, doublecomplex *a, integer *lda, 
	doublecomplex *tau, doublecomplex *c__, integer *ldc, doublecomplex *
	work, integer *lwork, integer *info);
 
/* Subroutine */ extern "C" int zunml2_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zunmlq_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zunmql_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zunmqr_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zunmr2_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *info);
 
/* Subroutine */ extern "C" int zunmr3_(char *side, char *trans, integer *m, integer *n, 
	integer *k, integer *l, doublecomplex *a, integer *lda, doublecomplex 
	*tau, doublecomplex *c__, integer *ldc, doublecomplex *work, integer *
	info);
 
/* Subroutine */ extern "C" int zunmrq_(char *side, char *trans, integer *m, integer *n, 
	integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zunmrz_(char *side, char *trans, integer *m, integer *n, 
	integer *k, integer *l, doublecomplex *a, integer *lda, doublecomplex 
	*tau, doublecomplex *c__, integer *ldc, doublecomplex *work, integer *
	lwork, integer *info);
 
/* Subroutine */ extern "C" int zunmtr_(char *side, char *uplo, char *trans, integer *m, 
	integer *n, doublecomplex *a, integer *lda, doublecomplex *tau, 
	doublecomplex *c__, integer *ldc, doublecomplex *work, integer *lwork,
	 integer *info);
 
/* Subroutine */ extern "C" int zupgtr_(char *uplo, integer *n, doublecomplex *ap, 
	doublecomplex *tau, doublecomplex *q, integer *ldq, doublecomplex *
	work, integer *info);
 
/* Subroutine */ extern "C" int zupmtr_(char *side, char *uplo, char *trans, integer *m, 
	integer *n, doublecomplex *ap, doublecomplex *tau, doublecomplex *c__,
	 integer *ldc, doublecomplex *work, integer *info);

#endif /* __CLAPACK_H */
#else
#include <stdlib.h>
typedef long int integer;
typedef double doublereal;
int dgesvd_(char *, char *, integer *, integer *, 
                       doublereal *, integer *, doublereal *, doublereal *, integer *, 
                       doublereal *, integer *, doublereal *, integer *, integer *)
{
   printf("Please compile with lapack.\n");
   exit(-1);
   return -1;
}
int dgetrf_(integer *, integer *, doublereal *, integer *,
                       integer *, integer *)
{
   printf("Please compile with lapack.\n");
   exit(-1);
   return -1;
}
int dgerqf_(integer *, integer *, doublereal *, integer *,
	         doublereal *, doublereal *, integer *, integer *)
{
   printf("Please compile with lapack.\n");
   exit(-1);
   return -1;
}

int dgetri_(integer *n, doublereal *a, integer *lda, integer *ipiv, doublereal *work, integer *lwork, integer *info)
{
   printf("Please compile with lapack.\n");
   exit(-1);
   return -1;
}

#endif

